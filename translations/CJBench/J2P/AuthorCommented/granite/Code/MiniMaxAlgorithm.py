

import math
import sys

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))

    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore = 0
        score1 = 0
        score2 = 0

        if depth == self.height: # Leaf node reached.
            return self.scores[index]

        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)

        if isMaximizer:
            # Maximizer player wants to get the maximum possible score.
            bestScore = max(score1, score2)
        else:
            # Minimizer player wants to get the minimum possible score.
            bestScore = min(score1, score2)

        if verbose:
            print(f"From {score1} and {score2}, {('Maximizer' if isMaximizer else 'Minimizer')} chooses {bestScore}")

        return bestScore

    def main():
        numLeafNodes = int(input("Enter the number of leaf nodes: "))
        if (numLeafNodes & (numLeafNodes - 1))!= 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            sys.exit(1)

        scores = list(map(int, input("Enter the scores for each leaf node: ").split()))
        isMaximizer = bool(int(input("Is it Maximizer's turn? (1 for true, 0 for false): ")))

        main = Main(scores)
        verbose = True # Set verbose to True to show intermediate steps.
        bestScore = main.miniMax(0, isMaximizer, 0, verbose)

        print(f"Scores: {main.scores}")
        print(f"The best score for {'Maximizer' if isMaximizer else 'Minimizer'} is {bestScore}")

    if __name__ == "__main__":
        main()

