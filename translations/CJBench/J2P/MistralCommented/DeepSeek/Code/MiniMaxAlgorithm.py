import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = self.log2(len(scores))  # Calculate height of tree based on number of scores

    @staticmethod
    def main(args):
        scanner = Scanner(System.stdin)  # Initialize scanner for user input

        # Read number of leaf nodes and check if it's a power of 2
        numLeafNodes = scanner.nextInt()
        if (numLeafNodes & (numLeafNodes - 1)) != 0:  # Check if number is power of 2 using bitwise AND
            print("Error: The number of leaf nodes must be a power of 2.")
            return

        # Initialize scores array
        scores = [0] * numLeafNodes
        for i in range(numLeafNodes):
            scores[i] = scanner.nextInt()  # Read scores from user

        # Initialize MiniMax algorithm
        miniMaxAlgorithm = Main(scores)

        # Read whether it's maximizer or minimizer turn
        isMaximizer = scanner.nextBoolean()

        # Read whether to be verbose or not
        verbose = True

        # Run MiniMax algorithm and print results
        bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)
        print("Scores:", scores)
        print("The best score for", "Maximizer" if isMaximizer else "Minimizer", "is", bestScore)

        scanner.close()  # Close scanner

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
            print(f"From {score1} and {score2}, {'Maximizer' if isMaximizer else 'Minimizer'} chooses {bestScore}")

        return bestScore

    def log2(self, n):
        return 0 if n == 1 else self.log2(n // 2) + 1

    def getScores(self):
        return self.scores

