import math

class Main:
    # Array to hold the scores
    scores = []
    # Height of the tree based on the number of scores
    height = 0

    # Constructor to initialize scores and calculate the height of the tree
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))

    def main(self):
        # Create a scanner object to read input from the console
        scanner = input()
        
        # Read the number of leaf nodes (scores) from user input
        numLeafNodes = int(scanner)
        
        # Check if the number of leaf nodes is a power of 2
        if (numLeafNodes & (numLeafNodes - 1)) != 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            return # Exit if the condition is not met
        
        # Initialize the scores array based on the number of leaf nodes
        scores = []
        
        # Read the scores from user input
        for i in range(numLeafNodes):
            scores.append(int(scanner))
        
        # Create an instance of Main with the provided scores
        miniMaxAlgorithm = Main(scores)
        
        # Read whether the player is a maximizer or minimizer
        isMaximizer = bool(scanner)
        
        # Set verbosity for output
        verbose = True 
        
        # Calculate the best score using the miniMax algorithm
        bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)
        
        # Print the scores and the best score determined by the algorithm
        print(scores)
        print("The best score for " + ("Maximizer" if isMaximizer else "Minimizer") + " is " + bestScore)
        
        # Close the scanner to prevent resource leaks
        scanner.close()

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
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, ("Maximizer" if isMaximizer else "Minimizer"), bestScore))
        
        # Return the best score found
        return bestScore

    # Helper method to calculate the logarithm base 2 of a number
    def log2(self, n):
        return (n == 1) * 0 or self.log2(n / 2) + 1

    # Getter method to retrieve the scores array
    def getScores(self):
        return self.scores

# Create an instance of Main with the provided scores
miniMaxAlgorithm = Main([1, 2, 3, 4, 5, 6, 7, 8])

# Read whether the player is a maximizer or minimizer
isMaximizer = True

# Set verbosity for output
verbose = True 

# Calculate the best score using the miniMax algorithm
bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)

# Print the scores and the best score determined by the algorithm
print(miniMaxAlgorithm.getScores())
print("The best score for " + ("Maximizer" if isMaximizer else "Minimizer") + " is " + bestScore)

# Close the scanner to prevent resource leaks
scanner.close()

