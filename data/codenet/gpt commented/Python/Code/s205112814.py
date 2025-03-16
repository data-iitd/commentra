# Read two integers n and m from input, where n is the number of gates and m is the number of conditions
n, m = map(int, input().split())

# Read m pairs of integers representing the lower and upper thresholds for each gate condition
gate_cond = [[int(x) for x in input().split()] for _ in range(m)]

# Determine the maximum lower threshold from the gate conditions
max_under_th = max([l[0] for l in gate_cond])

# Determine the minimum upper threshold from the gate conditions
min_upper_th = min([l[1] for l in gate_cond])

# Check if there is a valid range between the maximum lower threshold and minimum upper threshold
if min_upper_th - max_under_th >= 0:
    # If valid, calculate the number of integers in the range and print the result
    print(min_upper_th - max_under_th + 1)
else:
    # If no valid range exists, print 0
    print(0)
