n, k, x, y = map(int, input().split())
sum_ = 0
for i in range(1, n + 1):
    if i > k:
        sum_ += y
    else:
        sum_ += x
print(sum_)
