n = int(input())  # Read the number of test cases

# Initialize counters for each result type
ac_count = 0  # Count of AC submissions
wa_count = 0  # Count of WA submissions
tle_count = 0  # Count of TLE submissions
re_count = 0  # Count of RE submissions

# Loop through each test case
for _ in range(n):
    s = input()  # Read the result of a test case
    if s == "AC":  # Check if the result is AC
        ac_count += 1  # Increment the AC count
    elif s == "WA":  # Check if the result is WA
        wa_count += 1  # Increment the WA count
    elif s == "TLE":  # Check if the result is TLE
        tle_count += 1  # Increment the TLE count
    elif s == "RE":  # Check if the result is RE
        re_count += 1  # Increment the RE count

# Print the counts of each result type
print(f"AC x {ac_count}")
print(f"WA x {wa_count}")
print(f"TLE x {tle_count}")
print(f"RE x {re_count}")

# <END-OF-CODE>
