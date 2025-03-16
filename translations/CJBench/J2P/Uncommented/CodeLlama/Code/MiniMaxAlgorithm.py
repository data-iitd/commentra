
import math
import sys

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))

    def main(self):
        num_leaf_nodes = int(sys.stdin.readline().strip())
        if num_leaf_nodes & (num_leaf_nodes - 1) != 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            return
        scores = [int(x) for x in sys.stdin.readline().strip().split()]
        mini_max_algorithm = Main(scores)
        is_maximizer = bool(int(sys.stdin.readline().strip()))
        verbose = True
        best_score = mini_max_algorithm.mini_max(0, is_maximizer, 0, verbose)
        print(scores)
        print("The best score for " + ("Maximizer" if is_maximizer else "Minimizer") + " is " + str(best_score))

    def mini_max(self, depth, is_maximizer, index, verbose):
        best_score = None
        score1 = None
        score2 = None
        if depth == self.height:
            return self.scores[index]
        score1 = self.mini_max(depth + 1, not is_maximizer, index * 2, verbose)
        score2 = self.mini_max(depth + 1, not is_maximizer, (index * 2) + 1, verbose)
        if is_maximizer:
            best_score = max(score1, score2)
        else:
            best_score = min(score1, score2)
        if verbose:
            print("From %02d and %02d, %s chooses %02d" % (score1, score2, ("Maximizer" if is_maximizer else "Minimizer"), best_score))
        return best_score

    def log2(self, n):
        return (n == 1) * 0 + (n / 2) * (1 + self.log2(n / 2))

if __name__ == "__main__":
    main()

