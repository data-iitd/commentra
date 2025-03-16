# Declare a variable to hold the number of submissions
n = int(input())  # Read the number of submissions from the user

# Initialize counters for different result types
ac_count = 0  # Count of Accepted submissions
wa_count = 0  # Count of Wrong Answer submissions
tle_count = 0  # Count of Time Limit Exceeded submissions
re_count = 0  # Count of Runtime Error submissions

# Loop through each submission
for _ in range(n):
    s = input()  # Read the result of the current submission

    # Increment the respective counter based on the result
    if s == "AC":
        ac_count += 1  # Increment Accepted count
    elif s == "WA":
        wa_count += 1  # Increment Wrong Answer count
    elif s == "TLE":
        tle_count += 1  # Increment Time Limit Exceeded count
    elif s == "RE":
        re_count += 1  # Increment Runtime Error count

# Output the counts of each result type
print(f"AC x {ac_count}")  # Display Accepted count
print(f"WA x {wa_count}")  # Display Wrong Answer count
print(f"TLE x {tle_count}")  # Display Time Limit Exceeded count
print(f"RE x {re_count}")  # Display Runtime Error count

# <END-OF-CODE>
