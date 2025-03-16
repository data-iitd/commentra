d = int(input())  # number of test cases

for _ in range(d):  # iterate through each test case
    n = int(input())  # read the size of the grid

    if n == 1:  # if the size of the grid is 1
        print("#")  # print '#'
        if _ != d - 1:
            print()  # print newline if it's not the last test case
        continue  # move to the next test case

    map = [['#'] * (n + 2) for _ in range(n + 2)]  # initialize the map with '#' and '.'
    for i in range(n + 2):
        if i == 0 or i == n + 1:
            for j in range(n + 2):
                map[i][j] = '.'
        else:
            map[i][0] = '.'
            map[i][n + 1] = '.'

    # Read the grid
    for i in range(1, n + 1):
        row = input().strip()
        for j in range(n):
            map[i][j + 1] = row[j]

    # Function to find the path of 'O' in the grid
    def visit():
        nonlocal map, n
        directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]  # directions to move in 4 directions

        while True:
            sum_ = 0  # initialize sum to 0
            flag = 0  # initialize flag to 0

            while True:
                if map[y + directions[flag][0] * 2][x + directions[flag][1] * 2] != '#' and map[y + directions[flag][0]][x + directions[flag][1]] != ' ':
                    # check if the next cell is not a wall or empty
                    flag = (flag + 1) % 4  # increment flag

                    # mark the cell as visited
                    map[y + directions[flag][0]][x + directions[flag][1]] = ' '

                    # move to the next cell
                    y += directions[flag][0]
                    x += directions[flag][1]

                    sum_ += 1  # increment sum

                    break

            if flag == 0:  # if all 4 directions are visited
                if sum_ == 0:
                    break  # if no 'O' is found, break the loop

            if flag == 0 and sum_ == 0:
                break  # if no 'O' is found, break the loop

    visit()  # call the visit function

    # Print the grid
    for i in range(1, n + 1):
        print(''.join(map[i][1:-1]))

    if _ != d - 1:
        print()  # print newline if it's not the last test case

print("<END-OF-CODE>")