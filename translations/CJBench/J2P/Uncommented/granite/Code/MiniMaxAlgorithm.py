

import math
import sys

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))
        if (len(scores) & (len(scores) - 1))!= 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            sys.exit(1)

    def miniMax(self, depth, isMaximizer, index, verbose):
        bestScore
        score1
        score2
        if depth == self.height:
            return self.scores[index]
        score1 = self.miniMax(depth + 1, not isMaximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not isMaximizer, (index * 2) + 1, verbose)
        if isMaximizer:
            bestScore = max(score1, score2)
        else:
            bestScore = min(score1, score2)
        if verbose:
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, ("Maximizer" if isMaximizer else "Minimizer"), bestScore))
        return bestScore

    def getScores(self):
        return self.scores

if __name__ == "__main__":
    numLeafNodes = int(input("Enter the number of leaf nodes: "))
    scores = [int(x) for x in input("Enter the scores for the leaf nodes: ").split()]
    isMaximizer = bool(input("Is it Maximizer's turn? (True/False): "))
    verbose = True
    miniMaxAlgorithm = Main(scores)
    bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose)
    print("Scores:", miniMaxAlgorithm.getScores())
    print("Best score for", ("Maximizer" if isMaximizer else "Minimizer"), "is", bestScore)

