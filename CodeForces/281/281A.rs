use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let input = input.trim();

    if input.is_empty() {
        return;
    }

    let mut chars = input.chars();
    let first_char = chars.next().unwrap().to_uppercase().to_string();

    let rest: String = chars.collect();

    let capitalized_word = format!("{}{}", first_char, rest);

    println!("{}", capitalized_word);
}
