# Define the main function
def main():
    A, B = map(int, input().split())  # Read two integers from the user and store them in A and B
    if A < 10 and B < 10:  # Check if both A and B are less than 10
        print(A * B)  # If true, print the multiplication result
    else:
        print(-1)  # If the condition is false, print -1

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
