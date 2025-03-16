
# Read the number of gates and conditions from the input
n, m = map(int, input().split())

# Initialize a list to store the conditions for each gate
gate_cond = []

# Read the conditions for each gate and add them to the list
for _ in range(m):
    # Read two integers from the input and add them as a sub-list to gate_cond
    gate_cond.append(list(map(int, input().split())))

# Calculate the maximum lower threshold among all gates
max_under_th = max([l[0] for l in gate_cond])

# Calculate the minimum upper threshold among all gates
min_upper_th = min([l[1] for l in gate_cond])

# Check if the difference between the minimum upper threshold and the maximum lower threshold is non-negative
if min_upper_th - max_under_th >= 0:
    # If it is, print the difference plus one as the number of gates that can be activated
    print(min_upper_th - max_under_th + 1)
else:
    # If it's not, print zero, indicating that no gates can be activated
    print(0)