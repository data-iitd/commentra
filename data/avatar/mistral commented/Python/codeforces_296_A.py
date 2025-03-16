# Take an integer 'n' as input from the user
n = int(input())

# Take a list 'm' as input from the user, where each element is a single character
m = input().split()

# Initialize a boolean variable 'possible' with a default value of True
possible = True

# Iterate through each unique character 'i' in the list 'm'
for i in set(m):
    # Check if the character 'i' appears more than 'n/2 + 1' times in the list 'm'
    if m.count(i) >= n // 2 + 1:
        # If the condition is true, set 'possible' to False and break the loop
        possible = False
        break

# Print 'YES' if 'possible' is still True, otherwise print 'NO'
print('YES' if possible else 'NO')
