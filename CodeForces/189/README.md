# 189

## A

使用动态规划自顶向下（记忆化搜索）的方法
状态定义：solve(n) 表示长度为 n 的绳子能切出的最大段数
状态转移：对于每个长度 n，尝试切掉 a、b、c 中的任意一个长度
递推公式：solve(n) = max(solve(n-a)+1, solve(n-b)+1, solve(n-c)+1)

优化点：
- 使用记忆化数组 table 避免重复计算
- 使用引用 &ans 简化代码并提高效率
- 初始值设为很小的负数，确保无解情况能被正确处理

### 时间复杂度
- O(n)，因为每个状态只会计算一次

### 空间复杂度
O(n)，用于存储记忆化数组



<!-- BEGIN SUBMISSIONS -->

## Submissions

| ID | Problem | Verdict | Time | Memory | Language | When |
|------|---------|----------|------|---------|----------|----------|
| [293950369](https://codeforces.com/contest/189/submission/293950369) | B | OK | 122 ms | 100 KB | C++20 (GCC 13-64) | 2024-11-30 06:45:48 |
| [293949762](https://codeforces.com/contest/189/submission/293949762) | B | WRONG_ANSWER | 92 ms | 0 KB | C++20 (GCC 13-64) | 2024-11-30 06:40:44 |
| [293946308](https://codeforces.com/contest/189/submission/293946308) | B | WRONG_ANSWER | 92 ms | 0 KB | C++20 (GCC 13-64) | 2024-11-30 06:10:19 |
| [293946189](https://codeforces.com/contest/189/submission/293946189) | B | WRONG_ANSWER | 92 ms | 0 KB | C++20 (GCC 13-64) | 2024-11-30 06:09:20 |
| [293943809](https://codeforces.com/contest/189/submission/293943809) | A | OK | 62 ms | 100 KB | C++20 (GCC 13-64) | 2024-11-30 05:45:42 |
| [293943754](https://codeforces.com/contest/189/submission/293943754) | A | WRONG_ANSWER | 15 ms | 0 KB | C++20 (GCC 13-64) | 2024-11-30 05:45:04 |

*Last updated: 2024-11-30 06:46:07*

<!-- END SUBMISSIONS -->
