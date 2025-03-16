#######
# Code
#######

# Define the input parameters: number of elements 'n' and list 'a'
n, m = map(int, input().split())  # Read number of elements 'n' and number of operations 'm' from the input
a = list(map(int, input().split()))  # Read 'n' integers from the input and store them in list 'a'

# Sort the list 'a' in ascending order
a.sort()

# Define the list 'ope' of tuples, each containing an operation index and its priority
ope = [list(map(int, input().split())) for _ in range(m)]  # Read 'm' operations from the input, each consisting of an index and priority, and store them in list 'ope'

# Sort the list 'ope' in descending order based on their priorities
ope = sorted(ope, key=lambda x: x[1], reverse=True)  # Sort 'ope' in descending order based on their priorities

# Initialize index 'j' to point to the current operation in 'ope'
j = 0

# Iterate through each element 'i' in the sorted list 'a'
for i in range(n):
    # If the current element 'a[i]' is less than the priority of the current operation 'ope[j][1]', perform the operation
    if a[i] < ope[j][1]:
        # Update the current element 'a[i]' with the priority of the current operation 'ope[j][1]'
        a[i] = ope[j][1]
        # Decrease the count of the current operation 'ope[j][0]' by 1
        ope[j][0] -= 1
        # If the count of the current operation 'ope[j][0]' becomes 0, move to the next operation
        if ope[j][0] == 0:
            j += 1
            # If all operations have been processed, break the loop
            if j == len(ope):
                break
    # If the current element 'a[i]' is greater than or equal to the priority of the current operation 'ope[j][1]', break the loop
    else:
        break

# Print the sum of the updated list 'a'
print(sum(a))
