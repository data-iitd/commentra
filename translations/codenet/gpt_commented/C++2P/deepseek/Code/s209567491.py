def main():
    # Declare variables for number of friends (N), days (D), and initial chocolates (X)
    N, D, X = map(int, input().split())

    # Variable to store the total number of chocolates
    num_of_chocolate = 0

    # Array to hold the chocolate consumption rate for each friend
    A = []

    # Input the chocolate consumption rates for each friend
    for _ in range(N):
        A.append(int(input()))

    # Loop through each friend to calculate the number of chocolates they will consume
    for i in range(N):
        # Reset days and counter for each friend
        days = 0
        counter = 0

        # Calculate how many chocolates can be consumed within the given days
        j = 0
        while True:
            # Calculate the total days required to consume chocolates
            days = j * A[i] + 1
            # If the calculated days are within the limit, increment the counter
            if days <= D:
                counter += 1
            # Break the loop if the days exceed the limit
            else:
                break
            j += 1

        # Add the count of chocolates consumed by this friend to the total
        num_of_chocolate += counter

    # Add the initial chocolates to the total count
    num_of_chocolate += X

    # Output the total number of chocolates
    print(num_of_chocolate)


if __name__ == "__main__":
    main()
