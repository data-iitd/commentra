
n, m = map(int, input().split())
# Initialize the problem parameters `n` and `m`

gate_cond = [[int(x) for x in input().split()] for _ in range(m)]
# Read `m` lines of input, where each line contains two integers representing the lower and upper threshold values for a gate condition

max_under_th = max([l[0] for l in gate_cond])
# Calculate the maximum value among all the lower threshold values
# This is used to find the range of possible values for the output

min_upper_th = min([l[1] for l in gate_cond])
# Calculate the minimum value among all the upper threshold values
# This is also used to find the range of possible values for the output

if min_upper_th - max_under_th >= 0:
    print(min_upper_th - max_under_th + 1)
    # If the difference between the minimum upper threshold value and the maximum lower threshold value is non-negative,
    # calculate the number of possible values for the output by subtracting the maximum lower threshold value from the minimum upper threshold value and adding one
else:
    print(0)
    # If the difference is negative, print 0

