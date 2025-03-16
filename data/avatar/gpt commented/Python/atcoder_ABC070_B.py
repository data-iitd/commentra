# Read a line of input, split it into components, and convert each component to an integer, storing them in a list A
A = list(map(int, input().split()))

# Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
if A[1] <= A[2] or A[3] <= A[0]:
    # If the condition is true, print 0
    print(0)
else:
    # If the condition is false, sort the list A in ascending order
    A.sort()
    # Calculate the difference between the largest and the second largest elements in the sorted list and print the result
    print(A[2] - A[1])
