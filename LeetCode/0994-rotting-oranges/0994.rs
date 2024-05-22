use std::collections::VecDeque;

fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
    let mut grid = grid;
    let directions = vec![(0, 1), (1, 0), (0, -1), (-1, 0)];
    let mut queue = VecDeque::new();
    let mut minutes_passed = 0;

    // Initialize the queue with all initially rotten oranges
    for i in 0..grid.len() {
        for j in 0..grid[i].len() {
            if grid[i][j] == 2 {
                queue.push_back((i, j));
            }
        }
    }

    // Process the queue
    while let Some((x, y)) = queue.pop_front() {
        for (dx, dy) in &directions {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            if nx >= 0 && nx < grid.len() as i32 && ny >= 0 && ny < grid[0].len() as i32 {
                let (nx, ny) = (nx as usize, ny as usize);
                if grid[nx][ny] == 1 {
                    grid[nx][ny] = 2;
                    queue.push_back((nx, ny));
                }
            }
        }
    }

    // Check for any remaining fresh oranges
    for row in &grid {
        if row.contains(&1) {
            return -1; // Not all oranges can rot
        }
    }

    // Calculate the total minutes passed
    if !queue.is_empty() {
        minutes_passed += 1;
    }

    minutes_passed
}

fn main() {
    let grid = vec![vec![2,1,1], vec![1,1,0], vec![0,1,1]];
    println!("Minutes until all oranges rot: {}", oranges_rotting(grid));
}