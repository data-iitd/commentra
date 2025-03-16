
n = int(input())
array = [int(x) for x in input().split()]
odd = 0
even = 0
odd_ind = 0
even_ind = 0
for i in range(1, n+1):
    if array[i-1] % 2 == 0:
        even += 1
        even_ind = i
    else:
        odd += 1
        odd_ind = i
if odd > even:
    print(even_ind)
else:
    print(odd_ind)
