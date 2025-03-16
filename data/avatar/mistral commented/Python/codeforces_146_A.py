# Ask user for the number of elements in the list
n = int(input())

# Get the list of numbers from user input
number = list(map(int, list(input().split())))

# Initialize variables h1 and h2 to 0
h1 = 0
h2 = 0

# Iterate through the list of numbers
for i in range(n):
    # Check if the current number is not 4 and not 7
    if number[i] not in [4, 7]:
        # Print "NO" and break the loop if the condition is met
        print("NO")
        x += 1
        break

    # If the index is less than half the length of the list, add the number to h1
    if i < n // 2:
        h1 += number[i]

    # If the index is greater than or equal to half the length of the list, add the number to h2
    else:
        h2 += number[i]

# Check if the loop was broken due to a non-4 and non-7 number
if not x:
    # If h1 and h2 are equal, print "YES"
    if h1 == h2:
        print("YES")
    # If h1 and h2 are not equal, print "NO"
    else:
        print("NO")
