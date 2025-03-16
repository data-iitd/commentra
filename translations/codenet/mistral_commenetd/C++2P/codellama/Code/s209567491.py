
# Define the function
def main():
    # Initialize variables
    N = 0
    D = 0
    X = 0
    num_of_chocolate = 0
    counter = 0
    days = 0

    # Read input
    N, D, X = map(int, input().split())

    # Initialize array A to store the number of chocolate pieces for each day
    A = [0] * 101
    for i in range(N):
        A[i] = int(input())

    # Calculate the total number of chocolate pieces
    for i in range(N):
        # Initialize variables for inner loop
        days = 0
        counter = 0

        # Calculate the number of days this chocolate piece lasts
        for j in range(101):
            days = j * A[i] + 1
            if days <= D:
                counter += 1
            else:
                break

        # Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
        num_of_chocolate += counter

    # Add the extra chocolate
    num_of_chocolate += X

    # Output the result
    print(num_of_chocolate)

# Call the function
main()

