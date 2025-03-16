def visit(map, n):
    dx = [0, 1, 0, -1]  # Direction vectors for x-axis
    dy = [-1, 0, 1, 0]  # Direction vectors for y-axis
    ab = [2, 2, 2, 2]   # Array to store the previous steps
    flg = 0             # Direction flag
    x, y = 2, n        # Starting position (2, n)
    map[y][x] = ' '    # Mark the starting position as visited

    while True:
        sum_steps = 0
        while True:
            if map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' and map[y + dy[flg]][x + dx[flg]] != ' ':
                flg += 1
                break
            map[y + dy[flg]][x + dx[flg]] = ' '  # Mark the current position as visited
            y += dy[flg]  # Update the y-coordinate
            x += dx[flg]  # Update the x-coordinate
            sum_steps += 1  # Increment the step count

        if flg == 4:
            flg = 0  # Reset the flag if it reaches 4
        if sum_steps == 0:
            break  # Break the loop if no steps are taken
        ab[0] = ab[1]  # Update the array with the previous steps
        ab[1] = ab[2]
        ab[2] = sum_steps
        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
            break  # Break the loop if the pattern repeats


def main():
    d = int(input())  # Read the number of test cases

    for l in range(d):
        n = int(input())  # Read the size of the map

        if n == 1:
            print("#")  # Print a single '#' if the size is 1
            if l != d - 1:
                print()  # Add a newline between test cases
            continue

        # Initialize the map with borders and fill it with '#' and '.'
        map = [['#' for _ in range(n + 2)] for _ in range(n + 2)]
        for i in range(n + 2):
            for j in range(n + 2):
                if i == 0 or j == 0 or i == n + 1 or j == n + 1:
                    map[i][j] = '.'

        visit(map, n)  # Call the visit function to process the map

        # Print the processed map
        for i in range(1, n + 1):
            print(''.join(map[i][1:n + 1]))
        if l != d - 1:
            print()  # Add a newline between test cases


if __name__ == "__main__":
    main()

# <END-OF-CODE>
