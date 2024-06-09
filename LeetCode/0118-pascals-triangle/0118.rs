pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
    let mut result: Vec<Vec<i32>> = Vec::new();

    for i in 0..num_rows {
        let mut row: Vec<i32> = Vec::new();
        for j in 0..=i {
            if j == 0 || j == i {
                row.push(1)
            } else {
                row.push(result[(i-1) as usize][(j-1) as usize] + result[(i-1) as usize][j as usize])
            }
        }
        result.push(row)
    }

    result
}
