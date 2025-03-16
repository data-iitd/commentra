N, K = map(int, input().split())
as_dict = {i: 0 for i in range(1, N + 1)}

for _ in range(K):
    d = int(input())
    for _ in range(d):
        a = int(input())
        as_dict[a] += 1

ans = sum(1 for v in as_dict.values() if v == 0)
print(ans)

# <END-OF-CODE>
