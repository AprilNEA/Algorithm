pub fn max_coins(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut rec = vec![vec![0; n + 2]; n + 2];
    let mut val = vec![1; n + 2];

    for i in 0..n {
        val[i + 1] = nums[i];
    }

    for i in (0..n).rev() {
        for j in (i + 2)..(n + 2) {
            for k in (i + 1)..j {
                let total = val[i] * val[k] * val[j] + rec[i][k] + rec[k][j];
                rec[i][j] = rec[i][j].max(total);
            }
        }
    }

    rec[0][n + 1]
}