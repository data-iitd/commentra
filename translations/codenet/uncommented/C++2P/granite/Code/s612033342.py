
h, w, k = map(int, input().split())
hw = [[0 for _ in range(w)] for _ in range(h)]
for i in range(h):
  for j in range(w):
    if input() == '#':
      hw[i][j] = 1

def count(hw, a, b):
  return sum(hw[i][j] for i in range(h) if a & (1 << i) and b & (1 << j))

sum = 0
for i in range(1 << h):
  for j in range(1 << w):
    if count(hw, i, j) == k:
      sum += 1

print(sum)
