use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let input = input.trim();

    let mut numbers: Vec<char> = input.chars().filter(|&c| c != '+').collect();

    numbers.sort();

    let result: String = numbers
        .iter()
        .map(|&c| c.to_string())
        .collect::<Vec<String>>()
        .join("+");

    println!("{}", result);
}
