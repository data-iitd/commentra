# Take the number of elements in the list from user input
n = int(input())

# Initialize an empty list 'x' to store the input elements
x = list(int(i) for i in input().split())

# Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
a = []
b = []

# Iterate through the list 'x' and append even and odd elements to their respective lists
for i in range(0, n):
    if i % 2 == 0:
        a.append(x[i])
    else:
        b.append(x[i])

# Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
cnta = [0] * (100002 + 1)
cntb = [0] * (100002 + 1)

# Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
vala = 0
valb = 0

# Initialize two variables 'maxCnta' and 'maxCntb' to store the maximum count of an element in lists 'a' and 'b' respectively
maxCnta = 0
maxCntb = 0

# Iterate through list 'a' and update the count of each element in 'cnta'
for i in a:
    cnta[i] += 1

# Find the element with maximum count in list 'a' and update 'vala' and 'maxCnta'
for i in a:
    if maxCnta < cnta[i]:
        vala = i
        maxCnta = cnta[i]

# Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and 'maxCnta1'
for i in a:
    if maxCnta1 < cnta[i] and i != vala:
        maxCnta1 = cnta[i]
        vala1 = i

# Similar logic for list 'b'
for i in b:
    cntb[i] += 1

# Find the element with maximum count in list 'b' and update 'valb' and 'maxCntb'
for i in b:
    if maxCntb < cntb[i]:
        valb = i
        maxCntb = cntb[i]

# Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and 'maxCntb1'
for i in b:
    if maxCntb1 < cntb[i] and i != valb:
        maxCntb1 = cntb[i]
        valb1 = i

# Check if 'vala' and 'valb' are same or not
if valb != vala:
    # If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
    res = 0
    for i in a:
        if i != vala:
            res += 1
    for i in b:
        if i != valb:
            res += 1
    print(res)
else:
    # If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
    # and print the minimum of these two sums
    resa = 0
    resb = 0
    resa1 = 0
    resb1 = 0
    for i in a:
        if i != vala:
            resa += 1
        if i != vala1:
            resa1 += 1
    for i in b:
        if i != valb:
            resb += 1
        if i != valb1:
            resb1 += 1
    print(min(resa + resb1, resa1 + resb))
