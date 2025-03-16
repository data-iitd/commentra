
x, y, a, b, c = map(int, input().split())  # 1. Taking multiple integer inputs

# 2. Processing the first list of integers
p = sorted([int(i) for i in input().split()], reverse=True)[:x]

# 3. Processing the second list of integers
q = sorted([int(i) for i in input().split()], reverse=True)[:y]

# 4. Processing the third list of integers
r = sorted([int(i) for i in input().split()], reverse=True)

# 5. Combining and sorting the selected elements from p and q
pq = sorted(p + q)

# 6. Iterating through the range of the minimum of the sums of x+y, a+b, and c
for i in range(min(x + y, a + b, c)):
    # 7. Replacing elements in pq if they are less than the corresponding elements in r
    if pq[i] < r[i]:
        pq[i] = r[i]

# 8. Printing the sum of the modified pq list
print(sum(pq))

