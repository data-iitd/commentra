n = int(input())
l = list(map(int, input().split()))
cnt = 0

# Sorting the list
l.sort()

# Counting the number of valid triplets
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            if l[i] + l[j] > l[k]:
                cnt += 1
            else:
                break

print(cnt)
# <END-OF-CODE>
