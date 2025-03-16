n = int(input())
min_val = 1000000
max_val = -1000000
sum_val = 0

for _ in range(n):
    tmp = int(input())
    if min_val > tmp:
        min_val = tmp
    if max_val < tmp:
        max_val = tmp
    sum_val += tmp

print(min_val, max_val, sum_val)

# <END-OF-CODE>
