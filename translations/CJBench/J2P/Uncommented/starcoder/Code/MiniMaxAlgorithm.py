
import sys
import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = int(math.log(len(scores), 2))

    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore = 0
        score1 = 0
        score2 = 0
        if depth == self.height:
            return self.scores[index]
        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)
        if isMaximizer:
            bestScore = max(score1, score2)
        else:
            bestScore = min(score1, score2)
        if verbose:
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, "Maximizer" if isMaximizer else "Minimizer", bestScore))
        return bestScore

    def getScores(self):
        return self.scores

if __name__ == "__main__":
    numLeafNodes = int(input())
    if (numLeafNodes & (numLeafNodes - 1))!= 0:
        print("Error: The number of leaf nodes must be a power of 2.")
        sys.exit(1)
    scores = [int(input()) for _ in range(numLeafNodes)]
    isMaximizer = input() == "True"
    verbose = True
    bestScore = Main(scores).miniMax(0, isMaximizer, 0, verbose)
    print(scores)
    print("The best score for %s is %d" % ("Maximizer" if isMaximizer else "Minimizer", bestScore))

