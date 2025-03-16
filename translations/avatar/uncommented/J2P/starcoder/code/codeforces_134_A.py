
# <START-OF-CODE>
n = int(input())
arr = [int(x) for x in input().split()]
sum = 0
for i in range(n):
    sum += arr[i]
c = 0
sb = []
for i in range(n):
    if (sum - arr[i]) % (n - 1) == 0 and (sum - arr[i]) / (n - 1) == arr[i]:
        c += 1
        sb.append(str(i+1) + " ")
print(c)
print(" ".join(sb))
# 