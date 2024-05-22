def selection_sort(a, n):
    for i in range(n):
        ith = i
        for j in range(i + 1, n):
            if a[j] < a[ith]:
                ith = j
        a[i], a[ith] = a[ith], a[i]


if __name__ == '__main__':
    a = [66, 55, 78, 68, 94]
    selection_sort(a, 5)
    print(a)
