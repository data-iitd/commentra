def min(a, b):
    return b if a >= b else a

def main():
    # Read the number of problems (D) and the target score (G)
    D, G = map(int, input().split())

    # Create a list to hold the problems
    problems = []
    
    # Read the number of questions and bonus points for each problem
    for _ in range(D):
        number, bonus = map(int, input().split())
        problems.append((number, bonus))
    
    # Initialize the answer to a large number (infinity equivalent)
    ans = 10000
    
    # Iterate over all possible combinations of problems using bit manipulation
    for bit in range(1 << D):
        score = 0        # Initialize the score for the current combination
        solved = 0       # Initialize the count of solved problems
        ok = False       # Flag to check if the current combination meets the target score

        # Calculate the score and number of solved problems for the current combination
        for j in range(D):
            if bit & (1 << j):  # Check if the j-th problem is included
                score += (j+1)*100*problems[j][0] + problems[j][1]
                solved += problems[j][0]

        # If the current score is less than the target score (G)
        if score < G:
            for j in range(D-1, -1, -1):
                if not bit & (1 << j):
                    break
            # Attempt to solve additional questions from the rightmost problem
            for k in range(problems[j][0]):
                score += (j + 1) * 100  # Add score for solving one more question
                solved += 1              # Increment the count of solved problems
                if score >= G:           # Check if the target score is reached
                    ok = True
                    break
            # If the target score is still not reached, add the bonus points
            if not ok:
                score += problems[j][1]
                if score >= G:
                    ok = True  # Check again if the target score is reached
        else:
            ok = True  # If the score is already greater than or equal to G
        
        # If the current combination meets the target score, update the answer
        if ok:
            ans = min(ans, solved)  # Update the minimum number of solved problems
    
    # Output the minimum number of problems that need to be solved to reach the target score
    print(ans)

main()
