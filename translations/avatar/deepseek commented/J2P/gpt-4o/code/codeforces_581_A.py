def main():
    a = int(input())  # Read first integer input
    b = int(input())  # Read second integer input
    count = 0  # Initialize count to keep track of loop iterations

    # Loop continues until the condition is met to break
    while True:
        if a > 0 and b > 0:  # Check if both a and b are positive
            count += 1  # Increment count
            a -= 1  # Decrement a
            b -= 1  # Decrement b
        else:
            break  # Break the loop if a or b is not positive

    ans = a // 2 + b // 2  # Calculate the value of ans
    print(count, ans)  # Print the results

if __name__ == "__main__":
    main()

# <END-OF-CODE>
