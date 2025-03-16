n, k, q = map(int, input().split())

arr = [0] * (n + 1)

for _ in range(q):
    temp = int(input())
    arr[temp] += 1

for i in range(1, n + 1):
    if arr[i] > (q - k):
        print("Yes")
    else:
        print("No")

# <END-OF-CODE>
