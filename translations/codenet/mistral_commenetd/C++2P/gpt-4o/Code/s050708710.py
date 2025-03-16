# Main function starts here
def main():
    r, g, b, n = map(int, input().split())  # Read input values for red, green, blue colors and number of balls

    ans = 0  # Initialize answer variable to zero

    # Check all possible combinations of red, green and blue balls to find the answer
    for i in range(n // r + 1):  # Iterate through all possible combinations of red balls
        for j in range(n // g + 1):  # Iterate through all possible combinations of green balls
            num = n - r * i - g * j  # Calculate the number of blue balls needed to make up the total number of balls

            # Check if the number of blue balls is valid (non-negative and divisible by b)
            if num >= 0 and num % b == 0:
                ans += 1  # Increment the answer if the current combination is valid

    # Print the answer to the standard output
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
