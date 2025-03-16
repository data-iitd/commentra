

import math

class Main:
    # Constructor
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores)) # Calculate height of tree based on number of scores

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
            print(f"From {score1} and {score2}, {('Maximizer' if isMaximizer else 'Minimizer')} chooses {bestScore}")

        return bestScore

    # Getter method for scores
    def getScores(self):
        return self.scores

# Read number of leaf nodes and check if it's a power of 2
numLeafNodes = int(input("Enter the number of leaf nodes: "))
if (numLeafNodes & (numLeafNodes - 1))!= 0: # Check if number is power of 2 using bitwise AND
    print("Error: The number of leaf nodes must be a power of 2.")
    exit()

# Initialize scores array
scores = [int(input(f"Enter score for leaf node {i + 1}: ")) for i in range(numLeafNodes)]

# Initialize MiniMax algorithm
miniMaxAlgorithm = Main(scores)

# Read whether it's maximizer or minimizer turn
isMaximizer = bool(input("Is it Maximizer's turn? (True/False): "))

# Read whether to be verbose or not
verbose = bool(input("Do you want verbose output? (True/False): "))

# Run MiniMax algorithm and print results
bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)
print(f"Scores: {miniMaxAlgorithm.getScores()}")
print(f"The best score for {'Maximizer' if isMaximizer else 'Minimizer'} is {bestScore}")

