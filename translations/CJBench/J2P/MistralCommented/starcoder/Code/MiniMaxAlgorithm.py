
import math
import sys

class Main:
    # Declare instance variables
    scores = []
    height = 0

    # Constructor
    def __init__(self, scores):
        self.scores = scores
        self.height = int(math.log(len(scores), 2)) # Calculate height of tree based on number of scores

    # Main method
    def main(self):
        # Read number of leaf nodes and check if it's a power of 2
        numLeafNodes = int(input())
        if (numLeafNodes & (numLeafNodes - 1))!= 0: # Check if number is power of 2 using bitwise AND
            print("Error: The number of leaf nodes must be a power of 2.")
            return

        # Initialize scores array
        for i in range(numLeafNodes):
            self.scores.append(int(input())) # Read scores from user

        # Read whether it's maximizer or minimizer turn
        isMaximizer = input() == "True"

        # Read whether to be verbose or not
        verbose = input() == "True"

        # Run MiniMax algorithm and print results
        bestScore = self.miniMax(0, isMaximizer, 0, verbose)
        print("Scores: " + str(self.scores))
        print("The best score for " + ("Maximizer" if isMaximizer else "Minimizer") + " is " + str(bestScore))

    # MiniMax algorithm
    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore = 0
        score1 = 0
        score2 = 0

        # Base case: leaf node
        if depth == self.height:
            return self.scores[index]

        # Recursive call for minimizing player
        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)

        # Recursive call for maximizing player
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)

        # Determine best score based on whether maximizing or minimizing
        if isMaximizer:
            bestScore = max(score1, score2)
        else:
            bestScore = min(score1, score2)

        # Print verbose output if enabled
        if verbose:
            print("From " + str(score1) + " and " + str(score2) + ", " + ("Maximizer" if isMaximizer else "Minimizer") + " chooses " + str(bestScore))

        return bestScore

# Main method
if __name__ == "__main__":
    Main().main()

