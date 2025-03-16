n = int(input())
a = list(map(int, input().split()))

# Create a copy of the list 'a' named 'abs_a' to store the absolute values of its elements
abs_a = [abs(x) for x in a]

# Initialize the variables 'ans' and 'min' with zero and the first element of 'abs_a' respectively
ans = 0
min_abs = abs_a[0]

# Iterate through each element of the list 'abs_a' and update the variables 'ans' and 'min' accordingly
for e in abs_a:
    ans += e
    if min_abs > e:
        min_abs = e

# Initialize the variable 'num_negative' with zero and count the number of negative elements in the list 'a'
num_negative = sum(1 for x in a if x < 0)

# Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
if num_negative % 2:
    ans -= min_abs * 2

# Print the final answer 'ans' to the standard output
print(ans)
