# Include necessary libraries for input and output operations

def main():  # The main function is the entry point of the program
    A, B, C, X = map(int, input().split())  # Read the values of A, B, C, and X from the standard input
    
    cnt = 0  # Initialize a counter to count the number of combinations
    for a in range(A + 1):  # Iterate over the possible values of a (0 to A)
        for b in range(B + 1):  # Iterate over the possible values of b (0 to B)
            for c in range(C + 1):  # Iterate over the possible values of c (0 to C)
                total = 500 * a + 100 * b + 50 * c  # Calculate the total value of the coins
                if total == X:  # If the total equals X, increment the counter
                    cnt += 1
    print(cnt)  # Output the number of combinations that sum up to X

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
