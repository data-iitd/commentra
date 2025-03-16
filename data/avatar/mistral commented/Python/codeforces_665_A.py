# Define a function to map strings to integers
a, at = map(int, input().split())
# Read the first pair of integers (a and at) from the user input

b, bt = map(int, input().split())
# Read the second pair of integers (b and bt) from the user input

t1, t2 = map(int, input().split(':'))
# Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"

st = t2 + (t1 - 5) * 60  # Calculate the start time in seconds
# Convert the start time from HH:MM format to seconds

fin = st + at  # Calculate the finish time in seconds
# Calculate the finish time in seconds

now = 0  # Initialize the current time to zero
ans = 0  # Initialize the answer to zero

# Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
while now < fin and now < 1140:
    # If the next event starts after the current time, increment the answer
    if now + bt > st:
        ans += 1
    # Increment the current time by the duration of the next event
    now += b

# Print the final answer
print(ans)