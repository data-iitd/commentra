# Define the main function which is the entry point of the program.
def main():
    r, g, b, n = map(int, input().split())  # Read four integers from the standard input.
    ans = 0  # Initialize a variable 'ans' to 0 to store the count of valid combinations.

    # Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
    for i in range(n // r + 1):
        for j in range(n // g + 1):
            num = n - r * i - g * j  # Calculate the remaining value after using 'r * i' and 'g * j'.
            if num >= 0 and num % b == 0:  # Check if 'num' is non-negative and divisible by 'b'.
                ans += 1  # Increment 'ans' if the conditions are met.

    print(ans)  # Print the value of 'ans' which represents the count of valid combinations.

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
