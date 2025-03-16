
# Read the number of elements in the array
n = int(input())
# Read the elements of the array
l = list(map(int, input().split()))
# Sort the array in ascending order using bubble sort
for i in range(n-1):
  for j in range(i+1, n):
    if l[j] < l[i]:
      tmp = l[i]
      l[i] = l[j]
      l[j] = tmp
# Count the number of valid triangles that can be formed
cnt = 0
for i in range(n-2):
  for j in range(i+1, n-1):
    for k in range(j+1, n):
      if l[i] + l[j] > l[k]:
        cnt += 1
      else:
        break
# Print the count of valid triangles
print(cnt)
