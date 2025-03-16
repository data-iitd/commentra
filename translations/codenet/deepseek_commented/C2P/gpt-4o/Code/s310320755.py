# Main function to generate and print magic squares of size n
def main():
    arr = [[0] * 17 for _ in range(17)]  # 2D array to store the magic square

    # Infinite loop to keep the program running until n is 0
    while True:
        n = int(input())  # Read the size of the magic square from the user
        if n == 0:
            break  # Exit the loop if n is 0

        # Initialize the starting position and the counter
        flag = 1
        r = (n + 1) // 2 + 1  # Calculate the starting row
        c = (n + 1) // 2      # Calculate the starting column
        arr[r][c] = cnt = 1   # Set the initial value and start the counter

        # Loop to fill the magic square
        while cnt != n * n + 1:
            cnt += 1  # Increment the counter
            if flag:
                r += 1  # Move up-right
                c += 1  # Move up-right
                if c > n: c = 1  # Wrap around if column exceeds n
                if r > n: r = 1  # Wrap around if row exceeds n
                if arr[r][c]:  # Check if the position is already filled
                    flag = 0  # Change direction
                    cnt -= 1  # Decrement the counter to repeat the last position
                else:
                    arr[r][c] = cnt  # Fill the position
            else:
                r += 1  # Move down-left
                c -= 1  # Move down-left
                if c < 1: c = n  # Wrap around if column goes below 1
                if r > n: r = 1  # Wrap around if row exceeds n
                if arr[r][c]:  # Check if the position is already filled
                    flag = 0  # Change direction
                else:
                    arr[r][c] = cnt  # Fill the position
                    flag = 1  # Change direction for the next move

        # Print the generated magic square
        for r in range(1, n + 1):
            for c in range(1, n + 1):
                print(f"{arr[r][c]:4d}", end='')  # Print each element with formatting
                arr[r][c] = 0  # Reset the element for the next iteration
                if c == n:
                    print()  # Move to the next line after each row

if __name__ == "__main__":
    main()

# <END-OF-CODE>
