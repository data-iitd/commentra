
# Import the required modules
import sys

# Define a custom problem struct to store number and bonus
class problem:
    def __init__(self, number, bonus):
        self.number = number
        self.bonus = bonus

# Function to find minimum of two integers
def min(a, b):
    if a >= b:
        return b
    return a

# Main function starts the execution
def main():
    # Initialize variables D and G to read input from user
    D, G = map(int, input().split())

    # Create a slice of problem structs with size D
    problems = [problem(int(input()), int(input())) for _ in range(D)]
    # print("D", D, "G", G, "problems", problems) # Uncomment this line for debugging purposes

    # Initialize answer variable ans with a large value
    ans = 10000

    # Loop through all possible combinations of problems using binary numbers
    for bit in range(1 << D):
        # Initialize variables score and solved to calculate the score and number of problems solved
        score = 0
        solved = 0
        # Initialize variable ok to check if the current combination can form a valid solution
        ok = False

        # Loop through each problem in the slice
        for j in range(D):
            # Check if the current bit is set for the problem j
            if bit & (1 << j) != 0:
                # If set, add the score and solved count for the problem
                score += (j + 1) * 100 * problems[j].number + problems[j].bonus
                solved += problems[j].number

        # Check if the current combination can form a valid solution by checking if the score is greater than or equal to G
        if score < G:
            # If not, try to add more problems to the current combination to form a valid solution
            for j in range(D - 1, -1, -1):
                # Find the last problem that is not included in the current combination
                if bit & (1 << j) == 0:
                    # Loop through each number of the last problem and check if adding it to the current combination forms a valid solution
                    for k in range(problems[j].number):
                        # Add the score and solved count for the problem
                        score += (j + 1) * 100
                        solved += 1
                        # Check if the current combination can form a valid solution
                        if score >= G:
                            # If yes, set ok to true and break the inner loop
                            ok = True
                            break

                    # If adding all numbers of the last problem does not form a valid solution, check if adding the bonus of the last problem forms a valid solution
                    if problems[j].bonus > 0:
                        # Add the bonus of the last problem to the score and solved count
                        score += problems[j].bonus
                        solved += 1
                        # Check if the current combination can form a valid solution
                        if score >= G:
                            # If yes, set ok to true and break the inner loop
                            ok = True
                            break

        else:
            # If the current combination forms a valid solution, update the answer variable with the minimum solved count
            ok = True

        # If the current combination forms a valid solution, update the answer variable
        if ok:
            ans = min(ans, solved)

    # Print the answer variable
    print(ans)

# End of code
