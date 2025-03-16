def main():  # The main function to execute the program logic
    N = int(input())  # Read an integer input from the user and assign it to N
    i = 1  # Initialize the variable i to 1
    ans = 0  # Initialize the variable ans to 0
    while 10 ** i <= N:  # Start a while loop that continues as long as 10^i is less than or equal to N
        ans += (10 ** i) - (10 ** (i - 1))  # Add the difference between 10^i and 10^(i-1) to ans
        i += 2  # Increment i by 2 for the next iteration
    ans += max(0, N - 10 ** (i - 1) + 1)  # Add the maximum of 0 and N - 10^(i-1) + 1 to ans
    print(ans)  # Print the final value of ans

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function to execute the program logic
