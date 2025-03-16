def main():
    # Initialize variables
    n = int(input())

    as_list = [0] * (n + 1)  # Initialize array 'as' with size n+1
    bs_list = [0] * n        # Initialize array 'bs' with size n

    # Read elements of array 'as' from the standard input
    for i in range(n + 1):
        as_list[i] = int(input())

    # Read elements of array 'bs' from the standard input
    for i in range(n):
        bs_list[i] = int(input())

    # Initialize variable 'sum' to 0
    total_sum = 0

    # Iterate through each index 'i' of arrays 'as' and 'bs'
    for i in range(n):
        # Assign the value of 'as[i]' to variable 'a'
        a = as_list[i]

        # Assign the value of 'bs[i]' to variable 'b'
        b = bs_list[i]

        # If 'a' is less than or equal to 'b', add 'a' to 'sum' and subtract 'a' from 'b'
        if a <= b:
            total_sum += a
            b -= a

        # If there is an element after 'as[i]', check if it can be added to 'sum'
        if i + 1 < n + 1:
            # Assign the value of 'as[i+1]' to variable 'an'
            an = as_list[i + 1]

            # If 'an' is less than or equal to 'b', add 'an' to 'sum' and set 'as[i+1]' to 0
            if an <= b:
                total_sum += an
                as_list[i + 1] = 0
            else:
                # If 'an' is greater than 'b', add 'b' to 'sum' and subtract 'b' from 'an'
                total_sum += b
                as_list[i + 1] -= b

    # Print the final result 'sum' to the standard output
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
