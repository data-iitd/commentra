# The main function is the entry point of the program.
def main():
    # Read two integers A and B from the standard input.
    A, B = map(int, input().split())

    # Calculate the maximum value of A+B, A-B, and A*B using the max function.
    mx = max(A + B, A - B)
    mx = max(mx, A * B)

    # Print the maximum value.
    print(mx)

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
