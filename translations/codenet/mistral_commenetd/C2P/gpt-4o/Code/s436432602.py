# Function to run the logic of the program
def run():
    # Read input values of n and k from the user
    n, k = map(int, input("Enter the number of elements in the array and the target sum: ").split())

    # Read the elements of the array from the user
    a = list(map(int, input(f"Enter {n} integers: ").split()))

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
            if a[j] <= i and dp[i - a[j]] == 1:
                win = 1
                break

        # Update the dp value for the current sum i
        dp[i] = win

    # Print the result based on the dp value for the target sum k
    print(f"The target sum {k} is ", end="")
    if dp[k]:
        print("First")  # Target sum is a subset of given array
    else:
        print("Second")  # Target sum is not a subset of given array

# Main function to call the run function
if __name__ == "__main__":
    run()

# <END-OF-CODE>
