

import sys

# Initialize low and high arrays for quicksort
low = [0]
high = [0]

# Array 'a' to store elements after sorting
a = []

# Array 'b' to store elements for quicksort partitioning
b = []

# Function to partition the array using quicksort algorithm
def part(a, b, l, r):
  i = l - 1
  j = r
  x = b[r]

  while True:
    while b[++i] < x:
      pass
    while i < --j and x < b[j]:
      pass

    if i >= j:
      break

    a[i], a[j] = a[j], a[i]
    b[i], b[j] = b[j], b[i]

  a[i], a[r] = a[r], a[i]
  b[i], b[r] = b[r], b[i]
  return i

# Function to perform quicksort on the array 'a'
def quicksort(a, b, n):
  sp = 1
  while sp > 0:
    sp -= 1
    l = low[sp]
    r = high[sp]

    if l >= r:
      continue

    v = part(a, b, l, r)

    if v - l < r - v:
      low[sp] = v + 1
      high[sp] = r
      low[sp + 1] = l
      high[sp + 1] = v - 1
      sp += 1
    else:
      low[sp] = l
      high[sp] = v - 1
      low[sp + 1] = v + 1
      high[sp + 1] = r
      sp += 1

# Main function to read input and call quicksort
def main():
  n, m = map(int, sys.stdin.readline().split())
  a = []
  b = []
  for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    a.append(x)
    b.append(y)

  quicksort(a, b, m)

  t = 0
  cnt = 0
  for i in range(m):
    if t <= a[i]:
      t = b[i]
      cnt += 1

  print(cnt)

if __name__ == "__main__":
  main()

