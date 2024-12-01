def find_highest_floor(N, D, S):
    visited = set([S])
    queue = [S]
    highest = S
    
    while queue:
        current = queue.pop(0)
        k = 2
        while True:
            next_floor = current * k
            if next_floor > N or next_floor - current > D:
                break
            if next_floor not in visited:
                visited.add(next_floor)
                queue.append(next_floor)
                highest = max(highest, next_floor)
            k += 1
    
    return highest

N,D,S = map(int, input().split())
print(find_highest_floor(N, D, S))