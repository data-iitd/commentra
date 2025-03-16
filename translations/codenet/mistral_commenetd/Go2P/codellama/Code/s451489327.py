
# Initialize variables
n = 0

# Read the number of elements from the standard input
n = int(input())

# Initialize arrays 'as' and 'bs' with size n+1
as = [0] * (n+1)
bs = [0] * n

# Read elements of array 'as' from the standard input
for i in range(n):
    as[i] = int(input())

# Read elements of array 'bs' from the standard input
for i in range(n):
    bs[i] = int(input())

# Initialize variable 'sum' to 0
sum = 0

# Iterate through each index 'i' of arrays 'as' and 'bs'
for i in range(n):
    # Assign the value of 'as[i]' to variable 'a'
    a = as[i]

    # Assign the value of 'bs[i]' to variable 'b'
    b = bs[i]

    # If 'a' is less than or equal to 'b', add 'a' to 'sum' and subtract 'a' from 'b'
    if a <= b:
        sum += a
        b -= a

    # If there is an element after 'as[i]', check if it can be added to 'sum'
    if i+1 <= n-1:
        # Assign the value of 'as[i+1]' to variable 'an'
        an = as[i+1]

        # If 'an' is less than or equal to 'b', add 'an' to 'sum' and set 'as[i+1]' to 0
        if an <= b:
            sum += an
            as[i+1] = 0
        else:
            # If 'an' is greater than 'b', add 'b' to 'sum' and subtract 'b' from 'an'
            sum += b
            as[i+1] -= b

# Print the final result 'sum' to the standard output
print(sum)

