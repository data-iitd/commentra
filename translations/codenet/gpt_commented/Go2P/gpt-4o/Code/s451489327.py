# Read the size of the arrays from standard input
n = int(input())

# Initialize two lists: one for array 'as' with size n+1 and another for array 'bs' with size n
as_list = [0] * (n + 1)
bs_list = [0] * n

# Read values into the 'as' array
for i in range(n + 1):
    as_list[i] = int(input())

# Read values into the 'bs' array
for i in range(n):
    bs_list[i] = int(input())

# Initialize a variable to hold the cumulative sum
sum_value = 0

# Iterate through the elements of the arrays
for i in range(n):
    a = as_list[i]  # Current element from 'as'
    b = bs_list[i]  # Current element from 'bs'
    
    # Check if the current element of 'as' is less than or equal to the current element of 'bs'
    if a <= b:
        sum_value += a  # Add 'a' to the sum
        b -= a          # Subtract 'a' from 'b'
        
        # Check if there is a next element in 'as'
        if i + 1 < len(as_list):
            an = as_list[i + 1]  # Next element from 'as'
            # Check if the next element of 'as' can be fully accommodated by the remaining 'b'
            if an <= b:
                sum_value += an  # Add the next element to the sum
                as_list[i + 1] = 0  # Set the next element to zero since it has been fully used
            else:
                sum_value += b  # Add the remaining 'b' to the sum
                as_list[i + 1] -= b  # Subtract the used portion from the next element of 'as'
    else:
        # If 'a' is greater than 'b', add 'b' to the sum
        sum_value += b

# Output the final computed sum
print(sum_value)

# <END-OF-CODE>
