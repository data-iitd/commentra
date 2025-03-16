

import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))

    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore = 0
        score1 = 0
        score2 = 0

        # Base case: when depth equals the height of the tree
        if depth == self.height:
            return self.scores[index]

        # Recursively evaluate the scores for the left and right children
        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)

        # Determine the best score based on whether it's the Maximizer or Minimizer's turn
        if isMaximizer:
            bestScore = max(score1, score2)
        else:
            bestScore = min(score1, score2)

        # Print the choice if verbose mode is enabled
        if verbose:
            print(f"From {score1} and {score2}, {('Maximizer' if isMaximizer else 'Minimizer')} chooses {bestScore}")

        return bestScore

    def getScores(self):
        return self.scores

# Read the scores of the leaf nodes from the user
numLeafNodes = int(input("Enter the number of leaf nodes: "))

# Check if the number of leaf nodes is a power of 2
if (numLeafNodes & (numLeafNodes - 1))!= 0:
    print("Error: The number of leaf nodes must be a power of 2.")
    exit()

# Read the scores of the leaf nodes from the user
scores = [int(input(f"Enter the score for leaf node {i+1}: ")) for i in range(numLeafNodes)]

# Create an instance of the Main class with the scores array
miniMaxAlgorithm = Main(scores)
isMaximizer = bool(input("Is it Maximizer's turn? (True/False): "))
verbose = True

# Run the MiniMax algorithm to find the best score
bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)

# Print the scores array and the best score for the player
print(f"Scores: {scores}")
print(f"The best score for {'Maximizer' if isMaximizer else 'Minimizer'} is {bestScore}")

