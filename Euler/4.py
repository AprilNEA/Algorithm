def isPalind(n):
    strnub = str(n)
    length = len(strnub)
    mlength = int(length / 2 if length % 2 == 0 else (length - 1)/2)
    left = strnub[:mlength]
    right = strnub[mlength:]
    return left == r''.join(reversed(right))

max = 0
for i in range(100,1000):
    for j in range(100,1000):
        nub = i * j
        if isPalind(nub) and nub > max:
            max = nub
print(max)
        
