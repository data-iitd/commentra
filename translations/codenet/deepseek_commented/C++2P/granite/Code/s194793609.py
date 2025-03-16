
n = int(input()) # 1. Reading the input size `n`
a = list(map(int, input().split())) # 2. Reading the array elements
abs_a = [abs(x) for x in a] # 3. Creating a copy of the array with absolute values

ans = sum(abs_a) # 4. Calculating the sum of absolute values
min_abs = min(abs_a)
ans -= min_abs * 2 if n % 2 else 0 # 5. Adjusting the sum based on the number of negative elements

print(ans) # 6. Outputting the result
