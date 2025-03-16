n = int(input())  # 1. Reading the input size `n`
a = list(map(int, input().split()))  # 2. Reading the array elements

abs_a = [abs(x) for x in a]  # 3. Creating a copy of the array with absolute values

ans = sum(abs_a)  # 4. Calculating the sum of absolute values
min_abs_a = abs_a[0]
for e in abs_a:
    if min_abs_a > e:
        min_abs_a = e

num_negative = sum(1 for x in a if x < 0)  # 5. Counting the number of negative elements

if num_negative % 2:  # 6. Adjusting the sum based on the number of negative elements
    ans -= min_abs_a * 2

print(ans)  # 7. Outputting the result
