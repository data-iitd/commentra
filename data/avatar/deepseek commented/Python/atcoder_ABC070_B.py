
A = list(map(int, input().split()))  # Taking input from the user and converting it into a list of integers

# Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
if A[1] <= A[2] or A[3] <= A[0]:
    print(0)  # If either condition is true, print 0
else:
    A.sort()  # Sorting the list
    print(A[2] - A[1])  # Printing the difference between the third and second elements

