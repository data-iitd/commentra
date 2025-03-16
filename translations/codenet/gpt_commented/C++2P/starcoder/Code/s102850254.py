# Python 3.6.1
# <NAME>

# Global variables
d = 0 # Number of test cases
map = [] # 2D map representation
n = 0 # Size of the map

# Function to visit and modify the map based on certain conditions
def visit():
    # Direction vectors for moving in 4 possible directions (up, right, down, left)
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    sum = 0 # Initialize sum for the current direction
    flg = 0 # Flag for direction
    x = 2 # Starting position on the map
    map[y][x] ='' # Mark the starting position as visited
    ab = [2, 2, 2, 2] # Array to track the last three sums

    # Infinite loop to traverse the map
    while True:
        sum = 0 # Reset sum for the current direction
        while True:
            # Check if the next position is valid (not a wall and not already visited)
            if map[y + dy[flg] * 2][x + dx[flg] * 2]!= '#' and map[y + dy[flg]][x + dx[flg]]!='':
                flg += 1 # Change direction
                break # Exit the inner loop

            # Mark the current position as visited
            map[y + dy[flg]][x + dx[flg]] =''
            # Move to the next position
            y += dy[flg]
            x += dx[flg]
            sum += 1 # Increment the sum of visited positions

        # Reset direction if all 4 directions have been tried
        if flg == 4: flg = 0
        # Break the loop if no positions were visited in this direction
        if sum == 0: break
        # Update the history of sums
        ab[0] = ab[1]
        ab[1] = ab[2]
        ab[2] = sum
        # Break if the last three sums are all 1 (indicating a dead end)
        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1: break

# Main function
if __name__ == "__main__":
    # Read the number of test cases
    d = int(input())

    # Loop through each test case
    for l in range(d):
        # Read the size of the map
        n = int(input())

        # Handle the case where the map size is 1
        if n == 1:
            print("#") # Output a single wall
            if l!= d - 1: print() # Print a newline if not the last test case
            continue # Skip to the next test case

        # Initialize the map with walls and empty spaces
        for i in range(n + 2):
            map.append(['#'] * (n + 2)) # Resize the row to accommodate walls
            for j in range(n + 2):
                map[i][j] = '#' # Fill the map with walls
                # Set the border of the map to empty spaces
                if i == 0 or j == 0 or i == n + 1 or j == n + 1: map[i][j] = '.'

        # Call the visit function to modify the map
        visit()

        # Output the modified map
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                print(map[i][j], end = '') # Print each row of the map
            print() # Newline after each row
        # Print a newline between test cases if not the last one
        if l!= d - 1: print()

