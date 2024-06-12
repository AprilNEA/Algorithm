impl Solution1 {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort();
        let mut ans: usize = 0;

        let mut i: usize = 0;
        let mut j: usize = people.len() - 1;

        while i <= j {
            if i == j {
                ans += 1;
                break;
            }
            if people[i] + people[j] <= limit {
                i += 1;
            }
            j -= 1;
            ans += 1;
        }

        ans as i32
    }
}
