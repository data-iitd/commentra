N, A, B = map(int, input().split())
# The code starts by taking three inputs: N, A, and B. These inputs are used to determine the number of times a certain event will occur and how many times it will occur within a certain limit.

ans = A * (N//(A+B)) + min(A, N%(A+B))
# The next line calculates the total number of times the event occurs, which is A * (N//(A+B)). This is the integer division of N by (A+B), multiplied by A to find the total occurrences of the event up to that point.
# The remainder of the division, N%(A+B), is then calculated. This gives the remaining number of times the event can occur after the initial full cycles.
# The minimum function is used to ensure that the number of occurrences does not exceed the limit A, even if there are fewer than A occurrences left.

print(ans)
# Finally, the result is printed.