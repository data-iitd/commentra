# Input Parsing: The first line of the code takes three inputs from the user: `n`, `a`, and `b`. These inputs are expected to be integers.
n, a, b = map(int, input().split())

# Cost Calculation for Option 1: The second line calculates the cost of option 1, which is `n * a`.
cost_option_1 = n * a

# Cost Calculation for Option 2: The third line calculates the cost of option 2, which is `b`.
cost_option_2 = b

# Printing the Minimum Cost: The fourth line prints the minimum of the two calculated costs.
print(min(cost_option_1, cost_option_2))