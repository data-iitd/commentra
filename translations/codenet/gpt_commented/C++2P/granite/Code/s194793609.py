
n = int(input())
a = list(map(int, input().split()))
abs_a = [abs(x) for x in a]
ans = sum(abs_a)
min_abs = min(abs_a)
num_negative = sum(1 for x in a if x < 0)
if num_negative % 2:
    ans -= min_abs * 2
print(ans)
