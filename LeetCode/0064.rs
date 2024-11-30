struct Solution;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let xn = grid[0].len();
        let yn = grid.len();
        let mut dp = vec![vec![0; xn]; yn];
        dp[0][0] = grid[0][0];
        for y in 0..yn {
            for x in 0..xn {
                if y == 0 && x > 0 {
                    dp[y][x] = dp[y][x - 1] + grid[y][x];
                } else if x == 0 && y > 0 {
                    dp[y][x] = dp[y - 1][x] + grid[y][x];
                } else if x > 0 && y > 0 {
                    dp[y][x] = std::cmp::min(dp[y - 1][x], dp[y][x - 1]) + grid[y][x];
                }
            }
        }
        dp[yn - 1][xn - 1]
    }
}

fn main() {
    let result = Solution::min_path_sum(vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]]);
    println!("{}", result);

    let result = Solution::min_path_sum(vec![vec![1, 2, 3], vec![4, 5, 6]]);
    println!("{}", result);
}
