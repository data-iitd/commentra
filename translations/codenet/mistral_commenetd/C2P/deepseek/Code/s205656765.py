# Include necessary import statements

def main():
    # Declare variables A, B, C, X of type int
    A, B, C, X = map(int, input().split())

    # Initialize variable kosu to zero
    kosu = 0

    # Three nested for loops to check if X can be represented as 10*i + 2*j + k
    for i in range(A + 1):  # Loop through all possible values of i from 0 to A
        for j in range(B + 1):  # Loop through all possible values of j from 0 to B
            for k in range(C + 1):  # Loop through all possible values of k from 0 to C
                if X == (10 * i) + (2 * j) + k:  # Check if X equals the sum of 10*i, 2*j, and k
                    kosu += 1  # If so, increment the counter kosu

    # Print the result, which is the number of ways X can be represented as 10*i + 2*j + k
    print(kosu)

# Call the main function
if __name__ == "__main__":
    main()
