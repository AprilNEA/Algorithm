import os
import json
import subprocess
import pandas as pd


def get_duration(count, datas):
    count = 0
    for video_id, video in datas.items():
        for clip_id, clips in video["clip"].items():
            fps = clips["fps"]
            for scene in clips["scene_split"]:
                start_frame = scene["scene_cut"][0]
                end_frame = scene["scene_cut"][1]
                d = (end_frame - start_frame) / fps
                if d > 4:
                    count += 1
    return count
    # results.append(
    #     {
    #         "clip_id": scene["clip_id"],
    #         "duration": d,
    #     }
    # )
    # print(f"Video {video_id} Clip {clip_id} Scene {scene['scene_id']}")


def main():
    # os.mkdir("./tmp")
    # Convert results to a pandas DataFrame
    count = 0

    for i in range(20):
        s3_path = f"s3://dataset-hd-vg-130m/metafiles/hdvg_{i}.json"
        local_file_path = f"./tmp/{os.path.basename(s3_path)}"
        subprocess.run(f"s5cmd cp {s3_path} {local_file_path}", shell=True, check=True)
        with open(local_file_path, "r") as f:
            data = json.load(f)
        count += get_duration(count, data)

    print(count)


main()
