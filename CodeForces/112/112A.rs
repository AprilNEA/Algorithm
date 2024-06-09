use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut lines = input.lines();

    let string1 = lines.next().unwrap().trim().to_lowercase();
    let string2 = lines.next().unwrap().trim().to_lowercase();

    let result = string1.cmp(&string2);

    let output = match result {
        std::cmp::Ordering::Less => -1,
        std::cmp::Ordering::Greater => 1,
        std::cmp::Ordering::Equal => 0,
    };

    println!("{}", output);
}
