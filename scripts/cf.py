import os
import sys
import json
import requests
from datetime import datetime
from bs4 import BeautifulSoup


def get_codeforces_submissions(contest_id, handle="AprilNEA"):
    # Try API first
    api_url = f"https://codeforces.com/api/contest.status?contestId={contest_id}&handle={handle}"
    try:
        api_response = requests.get(api_url)
        api_response.raise_for_status()
        api_data = api_response.json()

        if api_data["status"] == "OK":
            submissions = []
            for sub in api_data["result"]:
                submission = {
                    "id": str(sub["id"]),
                    "when": datetime.fromtimestamp(sub["creationTimeSeconds"]).strftime(
                        "%Y-%m-%d %H:%M:%S"
                    ),
                    "who": sub["author"]["members"][0]["handle"],
                    "problem": sub["problem"]["index"],
                    "language": sub["programmingLanguage"],
                    "verdict": sub["verdict"],
                    "time": f"{sub['timeConsumedMillis']} ms",
                    "memory": f"{sub['memoryConsumedBytes'] // 1024} KB",
                }
                submissions.append(submission)
            return submissions

    except:
        # Fallback to web scraping if API fails
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
        }

        url = f"https://codeforces.com/contest/{contest_id}/my"

        try:
            response = requests.get(url, headers=headers)
            response.raise_for_status()

            soup = BeautifulSoup(response.text, "html.parser")

            table = soup.find("table", class_="status-frame-datatable")
            if not table:
                return "未找到提交表格"

            submissions = []
            rows = table.find_all("tr")[1:]  # Skip header row

            for row in rows:
                cols = row.find_all("td")
                if cols:
                    submission = {
                        "id": cols[0].find("a").text.strip(),
                        "when": cols[1].text.strip(),
                        "who": cols[2].find("a").text.strip(),
                        "problem": cols[3].find("a").text.strip(),
                        "language": cols[4].text.strip(),
                        "verdict": cols[5]
                        .find("span", class_="verdict-accepted")
                        .text.strip()
                        if cols[5].find("span", class_="verdict-accepted")
                        else cols[5].text.strip(),
                        "time": cols[6].text.strip(),
                        "memory": cols[7].text.strip(),
                    }
                    submissions.append(submission)

            return submissions
        except requests.exceptions.RequestException as e:
            return f"请求错误: {str(e)}"
        except Exception as e:
            return f"解析错误: {str(e)}"


def keep_data(contest_id: int, submissions):
    json_path = f"CodeForces/{contest_id}/submissions.json"
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump(submissions, f)


def insert_markdown(contest_id: int, submissions):
    # Try to find README.md
    readme_path = f"CodeForces/{contest_id}/README.md"
    if not os.path.exists(readme_path):
        print(f"README.md not found at {readme_path}")
        return

    # Read existing content
    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    # Format submissions into markdown table
    submission_text = "\n## Submissions\n\n"
    submission_text += "| ID | Problem | Verdict | Time | Memory | Language | When |\n"
    submission_text += "|------|---------|----------|------|---------|----------|----------|\n"

    for sub in submissions:
        submission_text += f"| [{sub['id']}](https://codeforces.com/contest/{contest_id}/submission/{sub['id']}) | {sub['problem']} | {sub['verdict']} | {sub['time']} | {sub['memory']} | {sub['language']} | {sub['when']} |\n"
    submission_text += (
        f"\n*Last updated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}*\n"
    )
    # Check if submission section already exists
    start_marker = "<!-- BEGIN SUBMISSIONS -->"
    end_marker = "<!-- END SUBMISSIONS -->"

    if start_marker in content and end_marker in content:
        # Replace existing section
        start_idx = content.find(start_marker)
        end_idx = content.find(end_marker) + len(end_marker)
        new_content = (
            content[:start_idx]
            + start_marker
            + "\n"
            + submission_text
            + "\n"
            + end_marker
            + content[end_idx:]
        )
    else:
        # Append new section
        new_content = (
            content.rstrip()
            + "\n\n"
            + start_marker
            + "\n"
            + submission_text
            + "\n"
            + end_marker
            + "\n"
        )

    # Write back to file
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(new_content)

    print(f"Updated {readme_path} with submission results")


def main():
    if len(sys.argv) != 2:
        print("Usage: python cf-submission.py <contest_id>")
        sys.exit(1)

    contest_id = int(sys.argv[1])
    submissions = get_codeforces_submissions(contest_id)
    keep_data(contest_id, submissions)
    insert_markdown(contest_id, submissions)


if __name__ == "__main__":
    main()
