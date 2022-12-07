
number = 600851475143

def eratosthenes(n):
     IsPrime = [True] * (n + 1)
     for i in range(2, int(n ** 0.5) + 1): 
         if IsPrime[i]:
             for j in range(i * i, n + 1, i): 
                 IsPrime[j] = False
     return [x for x in range(2, n + 1) if IsPrime[x]]

N = 100000000
primes = eratosthenes(N)
large = 2

def isPrime(p):
    return number % p == 0
for prime in primes:
    if isPrime(prime):
        print(prime)
        large = prime
print(large)