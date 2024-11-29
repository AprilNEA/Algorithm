import sys
from collections import defaultdict
import heapq

input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    
    revenue = defaultdict(int)
    for _ in range(k):
        b, c = map(int, input().split())
        revenue[b] += c
    
    pq = [-v for v in revenue.values()]
    heapq.heapify(pq)
    
    total = 0
    for _ in range(min(n, len(pq))):
        total += -heapq.heappop(pq)
    
    print(total)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
