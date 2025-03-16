
# Read the number of elements (n) and the number of elements to sum (k)
n, k = map(int, input().split())
# Read n integers and store them in the list p
p = list(map(int, input().split()))
# Perform selection sort on the list p
for i in range(n):
    l = i
    for j in range(i+1, n):
        if p[j] < p[l]:
            l = j
    if l!= i:
        m = p[i]
        p[i] = p[l]
        p[l] = m
# Sum the first k elements of the sorted list
o = sum(p[:k])
# Print the sum of the first k elements
print(o)
