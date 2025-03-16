
import sys

def is_solution(columns_count, x):
    # Create an array to track if all positions for each column are 'X'
    all_xs = [True] * columns_count  # Initialize all positions as true (all 'X's)

    # Check each character in the string
    for i in range(12):
        # If the character is not 'X', mark the corresponding column as false
        if x[i]!= 'X':
            all_xs[i % columns_count] = False

    # Check if any column has all 'X's
    for i in range(columns_count):
        if all_xs[i]:
            return True  # Return true if a valid solution is found

    return False  # Return false if no valid solution is found

def main():
    # Initialize BufferedReader to read input from the console
    br = sys.stdin

    # Initialize PrintWriter to output results to the console
    pw = sys.stdout

    # Read the number of test cases
    t = int(br.readline())

    # Process each test case
    for i in range(t):
        possible_solutions = 0  # Counter for possible solutions
        solutions = []  # To store the solutions
        s = br.readline().strip()  # Read the input string

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
        pw.write(str(possible_solutions) + '\n')
        pw.write(' '.join(solutions))
        pw.write('\n')

if __name__ == "__main__":
    main()

