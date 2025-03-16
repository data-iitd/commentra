n = int(input())
a = list(map(int, input().split()))

abs_a = [abs(x) for x in a]

ans = sum(abs_a)
min_abs_a = abs_a[0]
for e in abs_a:
    if min_abs_a > e:
        min_abs_a = e

num_negative = sum(1 for x in a if x < 0)

if num_negative % 2:
    ans -= min_abs_a * 2

print(ans)
