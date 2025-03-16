
# Python code to generate and print magic squares of size n

# Main function to generate and print magic squares of size n
def main():
    while True:
        n = int(input("Enter the size of the magic square (0 to exit): "))
        if n == 0:
            break
        arr = [[0 for _ in range(n)] for _ in range(n)] # 2D array to store the magic square
        r, c, cnt = (n + 1) // 2 + 1, (n + 1) // 2, 1 # Initialize the starting position and the counter
        flag = True # Direction flag

        # Loop to fill the magic square
        while cnt!= n*n + 1:
            cnt += 1 # Increment the counter
            if flag:
                r += 1 # Move up-right
                c += 1 # Move up-right
                if c > n: c = 1 # Wrap around if column exceeds n
                if r > n: r = 1 # Wrap around if row exceeds n
                if arr[r-1][c-1]: # Check if the position is already filled
                    flag = False # Change direction
                    cnt -= 1 # Decrement the counter to repeat the last position
                else:
                    arr[r-1][c-1] = cnt # Fill the position
            else:
                r += 1 # Move down-left
                c -= 1 # Move down-left
                if c < 1: c = n # Wrap around if column goes below 1
                if r > n: r = 1 # Wrap around if row exceeds n
                if arr[r-1][c-1]: # Check if the position is already filled
                    flag = False # Change direction
                else:
                    arr[r-1][c-1] = cnt # Fill the position
                    flag = True # Change direction for the next move

        # Print the generated magic square
        for r in range(n):
            for c in range(n):
                print(f"{arr[r][c]:4}", end="") # Print each element with formatting
                arr[r][c] = 0 # Reset the element for the next iteration
            print() # Move to the next line after each row

if __name__ == "__main__":
    main()

