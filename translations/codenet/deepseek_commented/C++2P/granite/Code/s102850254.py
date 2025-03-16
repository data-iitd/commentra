
d = int(input()) # Number of test cases

for l in range(d):
    n = int(input()) # Size of the map

    if n == 1:
        print("#") # Print a single '#' if the size is 1
        if l!= d - 1: print() # Add a newline between test cases
        continue

    map = [['#' for j in range(n + 2)] for i in range(n + 2)] # Initialize the map with borders and fill it with '#' and '.'
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            map[i][j] = '.'

    def visit():
        dx = [0, 1, 0, -1] # Direction vectors for x-axis
        dy = [-1, 0, 1, 0] # Direction vectors for y-axis
        sum = 0
        flg = 0
        x = 2
        y = n
        map[y][x] ='' # Mark the starting position as visited
        ab = [2, 2, 2, 2] # Array to store the previous steps

        while True:
            sum = 0
            while True:
                if map[y + dy[flg] * 2][x + dx[flg] * 2]!= '#' and map[y + dy[flg]][x + dx[flg]]!='':
                    flg = (flg + 1) % 4
                    break
                map[y + dy[flg]][x + dx[flg]] ='' # Mark the current position as visited
                y = y + dy[flg] # Update the y-coordinate
                x = x + dx[flg] # Update the x-coordinate
                sum = sum + 1 # Increment the step count
            if flg == 4: flg = 0 # Reset the flag if it reaches 4
            if sum == 0: break # Break the loop if no steps are taken
            ab[0] = ab[1] # Update the array with the previous steps
            ab[1] = ab[2]
            ab[2] = sum
            if ab[0] == 1 and ab[2] == 1 and ab[1] == 1: break # Break the loop if the pattern repeats

    visit() # Call the visit function to process the map

    # Print the processed map
    for i in range(1, n + 1):
        print(''.join(map[i][1:n + 1]))
    if l!= d - 1: print() # Add a newline between test cases

