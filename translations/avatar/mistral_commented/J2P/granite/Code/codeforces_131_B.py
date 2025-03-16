

# Initialize the count array to store the count of each number
cnt = [0] * 21

# Read the numbers one by one and update the count array accordingly
for _ in range(int(input())):
    num = int(input())
    cnt[num + 10] += 1

# Calculate the result using the given formula
res = sum(cnt[i] * cnt[20 - i] for i in range(10)) + (cnt[10] * (cnt[10] - 1)) // 2

# Print the result to the console
print(res)

