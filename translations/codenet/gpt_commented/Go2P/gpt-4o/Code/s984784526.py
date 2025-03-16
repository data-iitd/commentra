# Declare a list 'a' to hold integer inputs
a = [0] * 3

# Read three integers from standard input into the list 'a'
a[0], a[1], a[2] = map(int, input().split())

# Initialize counters for occurrences of the numbers 5 and 7
five = 0
seven = 0

# Iterate over the list to count occurrences of 5 and 7
for i in range(3):
    # Increment the 'five' counter if the current element is 5
    if a[i] == 5:
        five += 1
    # Increment the 'seven' counter if the current element is 7
    if a[i] == 7:
        seven += 1

# Check if there are exactly two occurrences of 5 and one occurrence of 7
if five == 2 and seven == 1:
    # Print "YES" if the condition is met
    print("YES")
else:
    # Print "NO" if the condition is not met
    print("NO")

# <END-OF-CODE>
