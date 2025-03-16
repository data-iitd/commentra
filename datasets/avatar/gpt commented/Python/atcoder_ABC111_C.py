# Read the number of elements
n = int(input())

# Read the elements into a list
x = list(int(i) for i in input().split())

# Initialize two lists to hold elements at even and odd indices
a = []
b = []

# Distribute elements into lists based on their index (even or odd)
for i in range(0, n):
    if i % 2 == 0:
        a.append(x[i])  # Append to list 'a' if index is even
    else:
        b.append(x[i])  # Append to list 'b' if index is odd

# Initialize counters for occurrences of elements in lists 'a' and 'b'
cnta = [0] * (100002 + 1)
cntb = [0] * (100002 + 1)

# Variables to track the most frequent elements in list 'a'
vala = 0
vala1 = 0
maxCnta = 0
maxCnta1 = 0

# Count occurrences of each element in list 'a'
for i in a:
    cnta[i] += 1

# Find the most frequent element in list 'a'
for i in a:
    if maxCnta < cnta[i]:
        vala = i
        maxCnta = cnta[i]

# Find the second most frequent element in list 'a'
for i in a:
    if maxCnta1 < cnta[i] and vala != i:
        maxCnta1 = cnta[i]
        vala1 = i

# Variables to track the most frequent elements in list 'b'
valb = 0
valb1 = 0
maxCntb = 0
maxCntb1 = 0

# Count occurrences of each element in list 'b'
for i in b:
    cntb[i] += 1

# Find the most frequent element in list 'b'
for i in b:
    if maxCntb < cntb[i]:
        valb = i
        maxCntb = cntb[i]

# Find the second most frequent element in list 'b'
for i in b:
    if maxCntb1 < cntb[i] and valb != i:
        maxCntb1 = cntb[i]
        valb1 = i

# Check if the most frequent elements from both lists are different
if valb != vala:
    res = 0
    # Count elements in 'a' that are not the most frequent element
    for i in a:
        if i != vala:
            res += 1
    # Count elements in 'b' that are not the most frequent element
    for i in b:
        if i != valb:
            res += 1
    # Print the total count of elements that are not the most frequent
    print(res)
else:
    # Initialize counters for elements not equal to the most frequent elements
    resa = 0
    resb = 0
    resa1 = 0
    resb1 = 0
    
    # Count elements in 'a' that are not the most frequent and second most frequent
    for i in a:
        if i != vala:
            resa += 1
        if i != vala1:
            resa1 += 1
            
    # Count elements in 'b' that are not the most frequent and second most frequent
    for i in b:
        if i != valb:
            resb += 1
        if i != valb1:
            resb1 += 1
            
    # Print the minimum of the two possible results
    print(min(resa + resb1, resa1 + resb))
