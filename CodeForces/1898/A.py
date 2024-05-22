def milica_and_string_corrected(test_cases):
    results = []

    for n, k, s in test_cases:
        current_b = s.count('B')
        operations = []

        # If the current number of B's is exactly k, no operations are needed
        if current_b == k:
            operations = []

        # If there are fewer than k B's, replace the first character with B
        elif current_b < k:
            operations = [(1, 'B')]

        # If there are more than k B's, find where the (k+1)-th 'B' occurs and replace up to that position with A
        else:
            # Find the position where the (k+1)-th 'B' occurs
            b_count = 0
            for i, char in enumerate(s):
                if char == 'B':
                    b_count += 1
                if b_count == k + 1:
                    operations = [(i, 'A')]
                    break

        results.append((len(operations), operations))

    return results

# Re-testing with the example test cases
milica_and_string_corrected(test_cases_example)



def main():
    t = int(input())
    test_cases = []
    for _ in range(t):
        n, k = map(int, input().split())
        s = input()
        test_cases.append((n, k, s))

    results = milica_and_string(test_cases)
    for result in results:
        print(result[0])
        for operation in result[1]:
            print(operation[0], operation[1])


# # Example test cases from the prompt
# test_cases_example = [
#     (5, 2, "AAABB"),
#     (5, 3, "AABAB"),
#     (5, 0, "BBBBB"),
#     (3, 0, "BAA"),
#     (10, 3, "BBBABBBBAB")
# ]
#
# milica_and_string(test_cases_example)
if __name__ == '__main__':
    main()
