d = int(input())  # Number of test cases

for _ in range(d):
    n = int(input())  # Size of the map

    if n == 1:
        print("#")  # Print a single '#' if the size is 1
        if _ != d - 1:
            print()  # Add a newline between test cases
        continue

    # Initialize the map with borders and fill it with '#' and '.'
    map = [['#'] * (n + 2) for _ in range(n + 2)]
    for i in range(n + 2):
        for j in range(n + 2):
            if i == 0 or j == 0 or i == n + 1 or j == n + 1:
                map[i][j] = '.'

    # Call the visit function to process the map
    visit(map, n)

    # Print the processed map
    for i in range(1, n + 1):
        print(''.join(map[i][1:-1]))
    if _ != d - 1:
        print()  # Add a newline between test cases

def visit(map, n):
    dx = [0, 1, 0, -1]  # Direction vectors for x-axis
    dy = [-1, 0, 1, 0]  # Direction vectors for y-axis
    flg = 0  # Variable to track the direction flag
    x, y = 2, n  # Starting position (2, n)
    map[y][x] = ' '  # Mark the starting position as visited
    ab = [2, 2, 2]  # Array to store the previous steps

    # Main loop to process the map
    while True:
        sum = 0
        while True:
            if map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' and map[y + dy[flg]][x + dx[flg]] != ' ':
                flg = (flg + 1) % 4
                break
            map[y + dy[flg]][x + dx[flg]] = ' '  # Mark the current position as visited
            y += dy[flg]  # Update the y-coordinate
            x += dx[flg]  # Update the x-coordinate
            sum += 1  # Increment the step count
        if sum == 0:
            break  # Break the loop if no steps are taken
        ab[0], ab[1], ab[2] = ab[1], ab[2], sum  # Update the array with the previous steps
        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
            break  # Break the loop if the pattern repeats

print("<END-OF-CODE>")