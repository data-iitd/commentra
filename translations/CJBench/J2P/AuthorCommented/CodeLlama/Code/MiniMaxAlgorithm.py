
import math


class MiniMax:
    def __init__(self, scores):
        self.scores = scores
        self.height = math.log2(len(scores))

    def miniMax(self, depth, is_maximizer, index, verbose):
        if depth == self.height:
            return self.scores[index]

        score1 = self.miniMax(depth + 1, not is_maximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not is_maximizer, (index * 2) + 1, verbose)

        if is_maximizer:
            best_score = max(score1, score2)
        else:
            best_score = min(score1, score2)

        if verbose:
            print(f"From {score1} and {score2}, {('Maximizer' if is_maximizer else 'Minimizer')} chooses {best_score}")

        return best_score

    def log2(self, n):
        return (n == 1) * 0 or self.log2(n // 2) + 1

    def get_scores(self):
        return self.scores


if __name__ == "__main__":
    import sys

    num_leaf_nodes = int(sys.stdin.readline().strip())
    if num_leaf_nodes & (num_leaf_nodes - 1) != 0:
        print("Error: The number of leaf nodes must be a power of 2.")
        sys.exit(1)

    scores = list(map(int, sys.stdin.readline().strip().split()))

    is_maximizer = bool(int(sys.stdin.readline().strip()))

    verbose = True  # Set verbose to True to show intermediate steps.
    best_score = MiniMax(scores).miniMax(0, is_maximizer, 0, verbose)

    print(scores)
    print(f"The best score for {('Maximizer' if is_maximizer else 'Minimizer')} is {best_score}")

