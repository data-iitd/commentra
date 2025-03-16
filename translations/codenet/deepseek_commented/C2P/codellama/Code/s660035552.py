#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

# Declare global arrays to be used in the quicksort algorithm
low = [0] * 200000
high = [0] * 200000
a = [0] * 200000

# Partition function to rearrange elements in array 'a' based on values in array 'b'
def part(a, b, l, r):
  i = l - 1
  j = r
  x = b[r]

  while True:
    while b[i + 1] < x:
      i += 1
    while i < j and x < b[j]:
      j -= 1

    if i >= j:
      break

    # Swap elements in array 'a'
    t = a[i]
    a[i] = a[j]
    a[j] = t
    # Swap elements in array 'b'
    t = b[i]
    b[i] = b[j]
    b[j] = t

  # Swap elements in array 'a' and 'b' to place pivot in the correct position
  t = a[i]
  a[i] = a[r]
  a[r] = t
  t = b[i]
  b[i] = b[r]
  b[r] = t

  return i

# Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
def quicksort(a, b, n):
  l, r, v = 0, 0, 0
  sp = 1

  # Initialize the stack with the first range to be sorted
  low[0] = 0
  high[0] = n - 1

  while sp > 0:
    sp -= 1
    l = low[sp]
    r = high[sp]

    if l >= r:
      continue

    # Partition the array and get the pivot index
    v = part(a, b, l, r)

    # Push the sub-ranges onto the stack based on the pivot position
    if v - l < r - v:
      low[sp] = v + 1
      high[sp] = r
      low[sp + 1] = l
      high[sp + 1] = v - 1
    else:
      low[sp] = l
      high[sp] = v - 1
      low[sp + 1] = v + 1
      high[sp + 1] = r

# Read the number of elements and the number of pairs
n, m = map(int, input().split())

# Read the pairs of integers into arrays 'a' and 'b'
for i in range(m):
  a[i], b[i] = map(int, input().split())

# Sort the pairs using the quicksort function
quicksort(a, b, m)

# Count the number of unique intervals
t = 0
for i in range(m):
  if t <= a[i]:
    t = b[i]
    cnt += 1

# Print the count of unique intervals
print(cnt)

