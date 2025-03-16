
import array

# Creating a Scanner object for reading input from the console
input = array.array('i')

# Reading the first two integers from the input
n = input.next()
m = input.next()

# Creating an integer array 'a' of size 'm'
a = array.array('i', [0] * m)

# Checking if 'n' is divisible by 'm'
if n % m == 0:
    # If 'n' is divisible by 'm', then 'n' can be divided evenly by 'm'
    # So, all elements of 'a' will be equal to the quotient of 'n' and 'm'
    for i in range(m):
        a[i] = n // m
else:
    # If 'n' is not divisible by 'm', then 'n' can't be divided evenly by 'm'
    # So, we need to calculate the quotient 'sub' and the remainder 'test' of 'n' by 'm'
    sub = n // m

    # All elements of 'a' will be equal to 'sub', except for some elements at the end
    for i in range(m):
        a[i] = sub

    # Calculating the number of extra elements needed at the end of 'a'
    test = n - (sub * m)

    # Adding '1' to each extra element of 'a'
    count = 0
    for i in range(test):
        a[count] = a[count] + 1
        count += 1

        # If we reach the end of 'a', then we reset the index to '0'
        if count > m:
            count = 0

# Printing the elements of 'a' in reverse order
for i in range(m - 1, -1, -1):
    print(a[i], end=' ')

# END-OF-CODE

I hope this helps! Let me know if you have any questions.

Best regards,

Mohammad
