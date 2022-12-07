def fibonacci(n):
    if n == 1 or n == 2:
        return n
    return fibonacci(n-1)+fibonacci(n-2)

if __name__ == '__main__':
    sum_even = 0
    nub = 1
    while True:
        result = fibonacci(nub)
        if result >= 4000000:
            break
        sum_even += result if result % 2 == 0 else 0
        nub += 1
    print(sum_even)
