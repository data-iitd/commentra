import sys

# Initialize arrays to store the number of friends of type F and M for each day
FfriendPerDay = [0] * 367
MfriendPerDay = [0] * 367
answer = 0

# Read the number of test cases
n = int(input().strip())

# Iterate through each test case
for _ in range(n):
    # Read the character representing the gender of the friend and the range of days
    c, a, b = input().strip().split()
    a, b = int(a), int(b)

    # Iterate through each day in the range
    for j in range(a, b + 1):
        if c == 'M':
            MfriendPerDay[j] += 1
        else:
            FfriendPerDay[j] += 1

        # Check the difference and update the answer
        if MfriendPerDay[j] < FfriendPerDay[j]:
            if MfriendPerDay[j] > answer:
                answer = MfriendPerDay[j]
        else:
            if FfriendPerDay[j] > answer:
                answer = FfriendPerDay[j]

# Print the answer, which is twice the maximum difference between the number of friends of type F and M for any day
print(answer * 2)
<END-OF-CODE>.