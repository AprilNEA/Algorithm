impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut array = vec![0; ((n + 1) as usize)];

        if n > 2 {
            array[1] = 1;
            array[2] = 1;
            for i in 3..((n + 1) as usize) {
                array[i] = array[i - 3] + array[i - 2] + array[i - 1];
            }
            return array[n as usize];
        } else if n == 2 {
            return 1;
        }

        return n;
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::Solution;

    #[test]
    fn test() {
        assert_eq!(Solution::foo_bar(...), test_data);
    }
}
