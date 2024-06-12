fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let input: i32 = input.trim().parse().unwrap();

    println!("{}", input);
}
