def main():
    # Initialize variables
    n = int(input())

    # Initialize arrays 'as' and 'bs' with size n+1 and n respectively
    as_ = list(map(int, input().split()))
    bs = list(map(int, input().split()))

    # Initialize variable 'sum' to 0
    sum_ = 0

    # Iterate through each index 'i' of arrays 'as' and 'bs'
    for i in range(n):
        # Assign the value of 'as[i]' to variable 'a'
        a = as_[i]

        # Assign the value of 'bs[i]' to variable 'b'
        b = bs[i]

        # If 'a' is less than or equal to 'b', add 'a' to 'sum' and subtract 'a' from 'b'
        if a <= b:
            sum_ += a
            b -= a
        else:
            # If 'a' is greater than 'b', add 'b' to 'sum' and subtract 'b' from 'a'
            sum_ += b
            a -= b

        # If there is an element after 'as[i]', check if it can be added to 'sum'
        if i + 1 < n:
            # Assign the value of 'as[i+1]' to variable 'an'
            an = as_[i + 1]

            # If 'an' is less than or equal to 'b', add 'an' to 'sum' and set 'as[i+1]' to 0
            if an <= b:
                sum_ += an
                as_[i + 1] = 0
            else:
                # If 'an' is greater than 'b', add 'b' to 'sum' and subtract 'b' from 'an'
                sum_ += b
                as_[i + 1] -= b

    # Print the final result 'sum' to the standard output
    print(sum_)

# Call the main function
main()
