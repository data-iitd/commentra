n = int(input())

x = list(map(int, input().split()))
q = int(input())

y = list(map(int, input().split()))

sum_count = 0

for i in range(q):
    for j in range(n):
        if y[i] == x[j]:
            sum_count += 1
            break

print(sum_count)

# <END-OF-CODE>
