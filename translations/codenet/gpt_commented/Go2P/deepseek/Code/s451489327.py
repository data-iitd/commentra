def main():
    # Read the size of the arrays from standard input
    n = int(input())

    # Initialize two lists: one for array 'as' with size n+1 and another for array 'bs' with size n
    as_ = list(map(int, input().split()))
    bs = list(map(int, input().split()))

    # Initialize a variable to hold the cumulative sum
    sum_ = 0
    # Iterate through the elements of the arrays
    for i in range(n):
        a = as_[i]  # Current element from 'as'
        b = bs[i]   # Current element from 'bs'
        
        # Check if the current element of 'as' is less than or equal to the current element of 'bs'
        if a <= b:
            sum_ += a  # Add 'a' to the sum
            b -= a     # Subtract 'a' from 'b'
            
            # Check if there is a next element in 'as'
            if i+1 < n:
                an = as_[i+1]  # Next element from 'as'
                # Check if the next element of 'as' can be fully accommodated by the remaining 'b'
                if an <= b:
                    sum_ += an  # Add the next element to the sum
                    as_[i+1] = 0  # Set the next element to zero since it has been fully used
                else:
                    sum_ += b  # Add the remaining 'b' to the sum
                    as_[i+1] -= b  # Subtract the used portion from the next element of 'as'
        else:
            # If 'a' is greater than 'b', add 'b' to the sum
            sum_ += b

    # Output the final computed sum
    print(sum_)

# Call the main function
main()
