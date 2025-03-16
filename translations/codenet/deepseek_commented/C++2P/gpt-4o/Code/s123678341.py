# Step 1: Reading Inputs
X, Y, Z, K = map(int, input().split())

# Step 2: List Initialization and Input
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

# Step 3: Sorting
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

# Step 4: Combining A and B
AB = []
for a in A:
    for b in B:
        AB.append(a + b)

# Step 5: Sorting AB
AB.sort(reverse=True)

# Step 6: Combining AB and C
ABC = []
for i in range(min(K, len(AB))):
    for c in C:
        ABC.append(AB[i] + c)

# Step 7: Sorting ABC
ABC.sort(reverse=True)

# Step 8: Output
for i in range(K):
    print(ABC[i])

# <END-OF-CODE>
