# Define the main function
def main():
    A, B = map(int, input().split())  # Read two integers from the input and store them in variables A and B
    if A < 10 and B < 10:  # Check if both A and B are less than 10
        print(A * B)  # If true, print the product of A and B
    else:  # If the condition is false
        print(-1)  # Print -1 as an error message

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
