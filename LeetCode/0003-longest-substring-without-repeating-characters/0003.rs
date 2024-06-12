pub fn length_of_longest_substring(s: String) -> i32 {
    let mut max = 0;
    let mut start = 0;
    let mut map = std::collections::HashMap::new();
    for (i, c) in s.chars().enumerate() {
        if let Some(&j) = map.get(&c) {
            start = start.max(j + 1);
        }
        max = max.max(i - start + 1);
        map.insert(c, i);
    }
    max as i32
}
