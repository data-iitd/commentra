# Define the main function
def main():
    # Input the number of friends, days, and initial chocolates
    N, D, X = map(int, input().split())
    
    # Input the chocolate consumption rates for each friend
    A = list(map(int, input().split()))
    
    # Initialize the total number of chocolates with the initial amount
    num_of_chocolate = 0

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

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
