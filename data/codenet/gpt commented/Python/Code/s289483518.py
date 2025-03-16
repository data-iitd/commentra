# Read the number of elements (n) and the number of operations (m) from input
n, m = map(int, input().split())

# Read the list of integers and sort it in ascending order
a = list(map(int, input().split()))
a.sort()

# Read the operations, each consisting of a count and a value, and sort them by value in descending order
ope = [list(map(int, input().split())) for _ in range(m)]
ope = sorted(ope, key=lambda x: x[1], reverse=True)

# Initialize a pointer for the current operation
j = 0

# Iterate through the sorted list of integers
for i in range(n):
    # Check if the current integer is less than the current operation's value
    if a[i] < ope[j][1]:
        # Replace the integer with the operation's value
        a[i] = ope[j][1]
        # Decrease the count of the current operation
        ope[j][0] -= 1
        
        # If the operation count reaches zero, move to the next operation
        if ope[j][0] == 0:
            j += 1
            # If there are no more operations left, exit the loop
            if j == len(ope):
                break
    else:
        # If the current integer is not less than the operation's value, exit the loop
        break

# Print the sum of the modified list of integers
print(sum(a))
