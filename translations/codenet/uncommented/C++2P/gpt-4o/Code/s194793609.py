n = int(input())

a = list(map(int, input().split()))

abs_a = [abs(x) for x in a]

ans = 0
min_val = abs_a[0]
for e in abs_a:
    ans += e
    if min_val > e:
        min_val = e

num_negative = sum(1 for e in a if e < 0)

if num_negative % 2:
    ans -= min_val * 2

print(ans)

# <END-OF-CODE>
