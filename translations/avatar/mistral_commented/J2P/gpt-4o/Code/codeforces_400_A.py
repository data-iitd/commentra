import sys

# Method to check if a given string represents a valid solution
def is_solution(columns_count, x):
    all_xs = [True] * columns_count  # Initialize a list to keep track of the presence of 'X' in each column

    # Iterate through the given string and mark the corresponding columns as not having 'X'
    for i in range(12):
        if x[i] != 'X':
            all_xs[i % columns_count] = False  # Update the corresponding column

    # Check if there is any column having 'X'
    for i in range(columns_count):
        if all_xs[i]:  # If 'X' is present in this column
            return True  # Return true as this is a valid solution

    return False  # If no column has 'X', then this is not a valid solution

def main():
    input = sys.stdin.read  # Read input from console
    data = input().splitlines()  # Split input into lines
    t = int(data[0])  # Read the number of test cases

    results = []  # Initialize a list to store results for each test case

    for i in range(1, t + 1):  # Iterate through each test case
        possible_solutions = 0  # Initialize the counter for the number of valid solutions
        solutions = []  # Initialize a list to store the valid solutions

        s = data[i]  # Read the given string

        # Check if the given string represents a valid solution
        if is_solution(12, s):
            solutions.append("1x12")  # Add the solution to the list
            possible_solutions += 1  # Increment the counter

        if is_solution(6, s):
            solutions.append("2x6")
            possible_solutions += 1

        if is_solution(4, s):
            solutions.append("3x4")
            possible_solutions += 1

        if is_solution(3, s):
            solutions.append("4x3")
            possible_solutions += 1

        if is_solution(2, s):
            solutions.append("6x2")
            possible_solutions += 1

        if is_solution(1, s):
            solutions.append("12x1")
            possible_solutions += 1

        # Write the output
        results.append(f"{possible_solutions} {' '.join(solutions)}")  # Store the result for this test case

    # Print all results
    print("\n".join(results))  # Output all results at once

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
