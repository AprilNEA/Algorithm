struct Solution;

impl Solution {
  pub fn unique_paths(m: i32, n: i32) -> i32 {
      let mut dp = vec![vec![0; n as usize]; m as usize];
      for i in 0..m as usize {
          dp[i][0] = 1;
      }
      for j in 0..n as usize {
          dp[0][j] = 1;
      }
      for i in 1..m as usize {
          for j in 1..n as usize {
              dp[i][j] = dp[i-1][j] + dp[i][j-1];
          }
      }
      dp[m as usize - 1][n as usize - 1]
  }
}

fn main() {
  let m = 3;
  let n = 7;
  let result = Solution::unique_paths(m, n);
  println!("{}", result);

  let m = 3;
  let n = 2;
  let result = Solution::unique_paths(m, n);
  println!("{}", result);

}
