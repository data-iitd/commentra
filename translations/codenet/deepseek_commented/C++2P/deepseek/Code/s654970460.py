n = int(input())  # Read the number of elements for the array 'a'.
a = list(map(int, input().split()))  # Read the elements of the array 'a' and store them in a list.
print(a[-1], end='')  # Output the last element of the array 'a'.
for i in range(1, n):  # Loop to output the remaining elements of the array 'a' in reverse order.
    print(f" {a[-i-1]}", end='')
print()  # End the line after outputting all the elements.
