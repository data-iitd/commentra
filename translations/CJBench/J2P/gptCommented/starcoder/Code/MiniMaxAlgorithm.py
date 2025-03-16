import math
import sys

class Main:
    # Array to hold the scores
    scores = []
    # Height of the tree based on the number of scores
    height = 0

    # Constructor to initialize scores and calculate the height of the tree
    def __init__(self, scores):
        self.scores = scores
        self.height = int(math.log(len(scores), 2))

    # Recursive method to implement the miniMax algorithm
    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore = 0
        score1 = 0
        score2 = 0

        # Base case: if the current depth equals the height of the tree, return the score at the current index
        if depth == self.height:
            return self.scores[index]

        # Recursively calculate scores for the left and right child nodes
        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)

        # Determine the best score based on whether the current player is a maximizer or minimizer
        if isMaximizer:
            bestScore = max(score1, score2)
        else:
            bestScore = min(score1, score2)

        # Print verbose output if enabled
        if verbose:
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, "Maximizer" if isMaximizer else "Minimizer", bestScore))

        # Return the best score found
        return bestScore

    # Helper method to calculate the logarithm base 2 of a number
    def log2(self, n):
        return 0 if n == 1 else self.log2(n / 2) + 1

    # Getter method to retrieve the scores array
    def getScores(self):
        return self.scores

if __name__ == "__main__":
    # Create a scanner object to read input from the console
    scanner = sys.stdin

    # Read the number of leaf nodes (scores) from user input
    numLeafNodes = int(scanner.readline())

    # Check if the number of leaf nodes is a power of 2
    if (numLeafNodes & (numLeafNodes - 1))!= 0:
        print("Error: The number of leaf nodes must be a power of 2.")
        exit(0) # Exit if the condition is not met

    # Initialize the scores array based on the number of leaf nodes
    scores = [0] * numLeafNodes

    # Read the scores from user input
    for i in range(numLeafNodes):
        scores[i] = int(scanner.readline())

    # Create an instance of Main with the provided scores
    miniMaxAlgorithm = Main(scores)

    # Read whether the player is a maximizer or minimizer
    isMaximizer = scanner.readline().strip().lower() == "true"

    # Set verbosity for output
    verbose = True

    # Calculate the best score using the miniMax algorithm
    bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)

    # Print the scores and the best score determined by the algorithm
    print(scores)
    print("The best score for %s is %d" % ("Maximizer" if isMaximizer else "Minimizer", bestScore))

    # Close the scanner to prevent resource leaks
    scanner.close()

