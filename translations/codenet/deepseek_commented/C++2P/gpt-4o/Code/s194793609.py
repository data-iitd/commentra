n = int(input())  # 1. Reading the input size `n`

a = list(map(int, input().split()))  # 2. Reading the array elements

abs_a = [abs(x) for x in a]  # 3. Creating a copy of the array with absolute values

ans = sum(abs_a)  # 4. Calculating the sum of absolute values
min_val = min(abs_a)

num_negative = sum(1 for x in a if x < 0)  # 5. Counting the number of negative elements

if num_negative % 2:  # 6. Adjusting the sum based on the number of negative elements
    ans -= min_val * 2

print(ans)  # 7. Outputting the result
# <END-OF-CODE>
