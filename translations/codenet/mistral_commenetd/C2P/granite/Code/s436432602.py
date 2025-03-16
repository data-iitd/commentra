

# Python code to calculate the target sum

# Function to run the logic of the program
def run():
    # Declare variables
    n, k = map(int, input("Enter the number of elements in the array and the target sum: ").split())

    # Declare an array of size n to store the elements of the array
    a = list(map(int, input("Enter {} integers: ".format(n)).split()))

    # Declare a dynamic array of size k+1 to store the dp values
    dp = [0] * (k + 1)

    # Initialize all dp values as false initially
    for i in range(k + 1):
        dp[i] = 0

    # Calculate the dp values for all sums from 1 to k
    for i in range(1, k + 1):
        win = 0

        # Check if there exists a subset of sum i in the given array a[]
        for j in range(n):
            # If a[j] can be included in the subset, then check for the next element
            if dp[i - a[j]] == 1:
                win = 1
                break

        # Update the dp value for the current sum i
        dp[i] = win

    # Print the result based on the dp value for the target sum k
    if dp[k]:
        print("The target sum {} is First".format(k))  # Target sum is a subset of given array
    else:
        print("The target sum {} is Second".format(k))  # Target sum is not a subset of given array

# Main function to call the run function
if __name__ == "__main__":
    # Call the run function to execute the logic
    run()

