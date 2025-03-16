def is_solution(columns_count, x):
    # Create a list to track if all positions for each column are 'X'
    all_xs = [True] * columns_count

    # Check each character in the string
    for i in range(len(x)):
        # If the character is not 'X', mark the corresponding column as False
        if x[i] != 'X':
            all_xs[i % columns_count] = False

    # Check if any column has all 'X's
    for is_all_x in all_xs:
        if is_all_x:
            return True  # Return True if a valid solution is found

    return False  # Return False if no valid solution is found

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the number of test cases
    t = int(data[0])
    line_index = 1

    # Process each test case
    for _ in range(t):
        possible_solutions = 0  # Counter for possible solutions
        solutions = []  # To store the solutions
        s = data[line_index]  # Read the input string
        line_index += 1

        # Check for various column configurations and append valid solutions
        if is_solution(12, s):
            solutions.append(" 1x12")
            possible_solutions += 1
        if is_solution(6, s):
            solutions.append(" 2x6")
            possible_solutions += 1
        if is_solution(4, s):
            solutions.append(" 3x4")
            possible_solutions += 1
        if is_solution(3, s):
            solutions.append(" 4x3")
            possible_solutions += 1
        if is_solution(2, s):
            solutions.append(" 6x2")
            possible_solutions += 1
        if is_solution(1, s):
            solutions.append(" 12x1")
            possible_solutions += 1

        # Output the number of possible solutions and the solutions themselves
        print(possible_solutions, end='')
        print(''.join(solutions))

if __name__ == "__main__":
    main()
