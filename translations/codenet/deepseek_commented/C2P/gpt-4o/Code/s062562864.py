# Define the main function
def main():
    # Read four integers from the user
    a, b, c, d = map(int, input().split())

    # Perform multiplication operations and store the results in i and j
    i = a * b
    j = c * d

    # Use an if-else statement to compare the results and print the larger one
    if i > j:
        print(i)
    else:
        print(j)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
