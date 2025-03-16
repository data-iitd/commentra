
import math
import sys

class Main:

    def __init__(self, scores):
        self.scores = scores
        self.height = int(math.log2(len(scores)))

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
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, "Maximizer" if isMaximizer else "Minimizer", bestScore))

        return bestScore

    def main(self):
        numLeafNodes = int(input())
        if numLeafNodes & (numLeafNodes - 1)!= 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            return

        scores = [0] * numLeafNodes
        for i in range(numLeafNodes):
            scores[i] = int(input())

        isMaximizer = input() == "True"

        verbose = True # Set verbose to true to show intermediate steps.
        bestScore = self.miniMax(0, isMaximizer, 0, verbose)

        print(scores)
        print("The best score for %s is %d" % ("Maximizer" if isMaximizer else "Minimizer", bestScore))

if __name__ == "__main__":
    main = Main(sys.argv)
    main.main()

