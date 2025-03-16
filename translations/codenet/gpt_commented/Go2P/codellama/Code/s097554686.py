
# Define a constant for the maximum size of the memory array
size = 100001

# Define a function to process each interval
def process_interval(l, r):
    # Increment the count at the start of the interval
    mem[l] += 1
    # Decrement the count just after the end of the interval
    mem[r] -= 1

# Define a function to calculate the number of overlapping intervals at each time point
def calculate_ans(t):
    # Initialize the answer with the count at time 0
    ans = mem[0]
    # Calculate the number of overlapping intervals at each time point
    for i in range(1, t + 1):
        # Update the current count based on the previous count
        mem[i] += mem[i - 1]
        # Update the answer if the current count is greater than the previous maximum
        if ans < mem[i]:
            ans = mem[i]
    # Return the maximum number of overlapping intervals
    return ans

# Read the number of intervals and the maximum time from input
n = int(input())
t = int(input())

# Create an array to store the count of overlapping intervals at each time point
mem = [0] * size

# Process each interval
for i in range(n):
    # Read the left and right bounds of the interval
    l, r = map(int, input().split())
    # Process the interval
    process_interval(l, r)

# Calculate the number of overlapping intervals at each time point
ans = calculate_ans(t)

# Print the maximum number of overlapping intervals
print(ans)

