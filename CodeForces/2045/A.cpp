#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

bool isConsonant(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return false;
    return true;
}

int solve(string S) {
    int freq[26] = {0};
    for (char c : S) {
        freq[c - 'A']++;
    }

    // 统计 NG 组合数量
    int ngCount = min(freq['N' - 'A'], freq['G' - 'A']);
    int originalN = freq['N' - 'A'];
    int originalG = freq['G' - 'A'];
    
    int flexY = freq['Y' - 'A'];
    int maxLength = 0;

    // 尝试两种情况：将NG作为单辅音和分开处理
    for (int ngPairNum = 0; ngPairNum <= ngCount; ngPairNum++) {
        // 重置频率数组
        freq['N' - 'A'] = originalN - ngPairNum;
        freq['G' - 'A'] = originalG - ngPairNum;
        
        int vowels = freq['A' - 'A'] + freq['E' - 'A'] + freq['I' - 'A'] + 
                     freq['O' - 'A'] + freq['U' - 'A'];
        int consonants = 0;
        
        // 统计辅音
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c != 'Y' && !isVowel(c)) {
                consonants += freq[c - 'A'];
            }
        }

        // 尝试不同的Y分配
        for (int yAsVowel = 0; yAsVowel <= flexY; yAsVowel++) {
            int yAsConsonant = flexY - yAsVowel;
            int totalVowels = vowels + yAsVowel;
            int totalConsonants = consonants + yAsConsonant;
            int currLength = 0;
            
            // 计算可以形成的CVC音节数量
            int cvcCount = min(totalVowels, totalConsonants / 2);
            
            // 计算可以形成的CVNGV音节数量
            int cvngvCount = min(min(totalVowels / 2, ngPairNum), totalConsonants);
            
            // 计算可以形成的NGVNG音节数量
            int ngvngCount = min(totalVowels, ngPairNum / 2);
            
            // 计算总长度
            // CVC: 3个字母
            // CVNGV: 5个字母
            // NGVNG: 5个字母
            currLength = max({
                cvcCount * 3,
                cvngvCount * 5,
                ngvngCount * 5
            });
            
            maxLength = max(maxLength, currLength);
        }
    }

    return maxLength;
}

int main() {
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}