# Declare variables N and D of integer type
# N and D should be positive integers less than or equal to 20
def main():
    # Initialize variables N and D using input function
    N, D = map(int, input().split())

    # Calculate the quotient of N by (D*2+1) and store it in variable ans
    ans = N // (D * 2 + 1)

    # Calculate the remainder of N by (D*2+1) and store it in variable rem
    rem = N % (D * 2 + 1)

    # Check if the remainder is zero or not
    if rem != 0:
        # If the remainder is not zero, increment the value of ans by 1
        ans += 1

    # Print the value of ans
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
