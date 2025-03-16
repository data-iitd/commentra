N, K = map(int, input().split())
as_ = [0] * N

for i in range(K):
    d = int(input())
    chosen_elements = list(map(int, input().split()))
    for element in chosen_elements:
        as_[element - 1] += 1

ans = 0
for count in as_:
    if count == 0:
        ans += 1

print(ans)
