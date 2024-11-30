struct Solution;

impl Solution {

  fn rob(nums: Vec<i32>) -> i32 {
      let size = nums.len();
      let mut dp = vec![0; size];
      dp[0] = nums[0];
      dp[1] = std::cmp::max(nums[0], nums[1]);
      for i in 2..size {
          dp[i] = std::cmp::max(dp[i-1], dp[i-2] + nums[i]);
      }
      dp[size-1]
  }

  pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
       let max_num = *nums.iter().max().unwrap();
       let mut sums = vec![0; max_num as usize + 1];
       for &num in &nums {
           sums[num as usize] += num;
       }
       Self::rob(sums)
  }
}

fn main() {
    let nums = vec![3,4,2];
    let result = Solution::delete_and_earn(nums);
    println!("{}", result);

    let nums = vec![2,2,3,3,3,4];
    let result = Solution::delete_and_earn(nums);
    println!("{}", result);
}
