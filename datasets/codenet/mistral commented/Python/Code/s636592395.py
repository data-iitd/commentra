
#!python3

# input
N = int(input("Read the number of elements in the list from the user."))
A = list(map(int, input("Read the list of integers from the user, separated by spaces.").split()))


def main():
    "Define the main function to find the difference between the maximum and minimum elements in the list."
    A.sort() # Sort the list in ascending order
    ans = A[-1] - A[0] # Calculate the difference between the last and first elements
    print("Print the result.")
    print(ans)


if __name__ == "__main__":
    "Check if the script is being run directly or imported as a module."
    main() # Call the main function to execute the code.