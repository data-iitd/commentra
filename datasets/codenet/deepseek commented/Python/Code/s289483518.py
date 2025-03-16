n, m = map(int, input().split())  # Read the number of elements and the number of operations
a = list(map(int, input().split()))  # Read the list of elements
a.sort()  # Sort the list of elements
ope = [list(map(int, input().split())) for _ in range(m)]  # Read the list of operations
ope = sorted(ope, key=lambda x: x[1], reverse=True)  # Sort operations by their second element in descending order
j = 0
for i in range(n):
    if a[i] < ope[j][1]:  # Check if the current element is less than the second element of the current operation
        a[i] = ope[j][1]  # Replace the element with the second element of the operation
        ope[j][0] -= 1  # Decrement the count of the current operation
        if ope[j][0] == 0:  # Check if the current operation is fully applied
            j += 1  # Move to the next operation
            if j == len(ope):  # Check if all operations are applied
                break  # Break the loop if all operations are applied
    else:
        break  # Break the loop if the current element is not less than the operation value
print(sum(a))  # Print the sum of the modified list
