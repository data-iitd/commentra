
h, a = map(int, input().strip().split())
# Read two integers from input

ans = h // a
# Calculate integer division of h by a and store the result in ans

ama = h % a
# Calculate the remainder of h divided by a and store the result in ama

if ama != 0:
  ans += 1
# If there is a remainder, increment ans by 1

print(ans)
# Print the final value of ans

