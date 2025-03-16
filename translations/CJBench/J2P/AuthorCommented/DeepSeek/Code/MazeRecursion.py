def solve_maze_using_first_strategy(map):
    if set_way(map, 1, 1):
        return map
    return None


def solve_maze_using_second_strategy(map):
    if set_way2(map, 1, 1):
        return map
    return None


def set_way(map, i, j):
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True

    if map[i][j] == 0:
        map[i][j] = 2

        # Move down
        if set_way(map, i + 1, j):
            return True
        # Move right
        elif set_way(map, i, j + 1):
            return True
        # Move up
        elif set_way(map, i - 1, j):
            return True
        # Move left
        elif set_way(map, i, j - 1):
            return True

        map[i][j] = 3  # Mark as dead end (3) if no direction worked
        return False
    return False


def set_way2(map, i, j):
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True

    if map[i][j] == 0:
        map[i][j] = 2

        # Move up
        if set_way2(map, i - 1, j):
            return True
        # Move right
        elif set_way2(map, i, j + 1):
            return True
        # Move down
        elif set_way2(map, i + 1, j):
            return True
        # Move left
        elif set_way2(map, i, j - 1):
            return True

        map[i][j] = 3  # Mark as dead end (3) if no direction worked
        return False
    return False


