
n = int(input())  # Input the number of elements for the array 'a'.
a = [int(input()) for _ in range(n)]  # Input 'n' integer inputs and store them in the list 'a'.
print(a[-1], end=" ")  # Output the last element of the list 'a'.
for i in range(n-2, -1, -1):  # Loop to output the remaining elements of the list 'a' in reverse order.
    print(a[i], end=" ")
print()  # End the line after outputting all the elements.

