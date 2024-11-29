nm = int(input())

def solve():
  n = int(input())
  melodies = list(map(int, input().split()))
  for i in range(1, len(melodies)):
    diff = abs(melodies[i] - melodies[i - 1])
    if diff != 5 and diff != 7:
      print("NO")
      return
  print("YES")

for _ in range(nm):
    solve()