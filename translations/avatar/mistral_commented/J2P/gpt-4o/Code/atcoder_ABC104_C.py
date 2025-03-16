# Importing the required library
import sys

# Declaring a constant integer variable named INF
INF = 100000

# Main function declaration
def main():
    # Reading the number of test cases D from the standard input
    D = int(input())
    
    # Reading the goal score G from the standard input
    G = int(input())
    
    # Declaring and initializing two lists p and c of size D
    p = [0] * D
    c = [0] * D
    
    # Reading the values of p[i] and c[i] for each test case i from the standard input
    for i in range(D):
        p[i], c[i] = map(int, input().split())
    
    # Initializing a variable min to a large value
    min_solved = INF
    
    # Looping through all possible combinations of bits using a binary number
    for bit in range(1 << D):
        # Initializing variables score and solve_num to zero
        score = 0
        solve_num = 0
        
        # Looping through each test case i
        for i in range(D):
            # Checking if the current bit is set in the binary number
            if (bit & (1 << i)) != 0:
                # Adding the score for the current test case i to the total score
                score += 100 * (i + 1) * p[i] + c[i]
                # Incrementing the number of test cases solved so far
                solve_num += p[i]
        
        # Checking if the current combination of bits can form a valid solution
        if score < G:
            # Backtracking to find the minimum number of test cases to be solved
            for i in range(D - 1, -1, -1):
                # If the current bit is not set in the binary number
                if (bit & (1 << i)) == 0:
                    # Looping through each test case j that can be added to the current solution
                    for j in range(p[i] - 1):
                        # Adding the score for the current test case i and the current test case j to the total score
                        score += 100 * (i + 1)
                        # Incrementing the number of test cases solved so far
                        solve_num += 1
                        # Checking if the current combination of bits can form a valid solution
                        if score >= G:
                            break
                # If we have found a valid solution, we can break out of the outer loop as well
                if score >= G:
                    break
        
        # Updating the minimum number of test cases if the current combination of bits can form a valid solution with a smaller number of test cases
        if score >= G:
            min_solved = min(min_solved, solve_num)
    
    # Printing the minimum number of test cases required to form a valid solution
    print(min_solved)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
