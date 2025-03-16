n = int(input())  # Input the number of elements for the array 'a'.
a = [int(input()) for i in range(n)]  # Input the elements for the array 'a'.
print(a[n-1], end=" ")  # Output the last element of the array 'a'.
for i in range(1, n):  # Loop to output the remaining elements of the array 'a' in reverse order.
    print(a[n-i-1], end=" ")
print()  # End the line after outputting all the elements.
#