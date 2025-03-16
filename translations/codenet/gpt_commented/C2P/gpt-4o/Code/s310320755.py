def main():
    # Initialize a 16x16 array to store the magic square, filled with zeros
    arr = [[0] * 17 for _ in range(17)]  # Using 1-based indexing

    while True:
        # Read the size of the magic square
        n = int(input())
        # Exit the loop if the input is zero
        if n == 0:
            break
        
        # Initialize flag and starting position for the first number
        flag = 1
        r = (n + 1) // 2 + 1  # Starting row
        c = (n + 1) // 2      # Starting column
        arr[r][c] = cnt = 1   # Place the first number in the array

        # Loop to fill the magic square until all numbers are placed
        while cnt != n * n + 1:
            cnt += 1  # Increment the counter for the next number
            
            # If flag is set, move diagonally up-right
            if flag:
                r += 1  # Move down one row
                c += 1  # Move right one column
                
                # Wrap around if going out of bounds
                if c > n:
                    c = 1  # Wrap to the first column
                if r > n:
                    r = 1  # Wrap to the first row

                # Check if the current position is already filled
                if arr[r][c]:
                    flag = 0  # Change direction if the position is occupied
                    cnt -= 1  # Decrement the counter to retry placing the number
                else:
                    arr[r][c] = cnt  # Place the number in the array
            else:  # If flag is not set, move down-left
                r += 1  # Move down one row
                c -= 1  # Move left one column
                
                # Wrap around if going out of bounds
                if c < 1:
                    c = n  # Wrap to the last column
                if r > n:
                    r = 1  # Wrap to the first row

                # Check if the current position is already filled
                if arr[r][c]:
                    flag = 0  # Change direction if the position is occupied
                else:
                    arr[r][c] = cnt  # Place the number in the array
                    flag = 1  # Reset flag to move diagonally up-right next

        # Print the completed magic square
        for r in range(1, n + 1):
            for c in range(1, n + 1):
                print(f"{arr[r][c]:4d}", end='')  # Print each number in the magic square
                arr[r][c] = 0  # Reset the position in the array for the next iteration
                if c == n:
                    print()  # Print a newline at the end of each row

if __name__ == "__main__":
    main()

# <END-OF-CODE>
