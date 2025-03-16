import math

class MiniMax:
    def __init__(self, scores):
        self.scores = scores
        self.height = self.log2(len(scores))

    @staticmethod
    def main():
        num_leaf_nodes = int(input())
        if (num_leaf_nodes & (num_leaf_nodes - 1)) != 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            return

        scores = [int(input()) for _ in range(num_leaf_nodes)]

        mini_max_algorithm = MiniMax(scores)

        is_maximizer = input().strip() == 'True'

        verbose = True  # Set verbose to true to show intermediate steps.
        best_score = mini_max_algorithm.mini_max(0, is_maximizer, 0, verbose)

        print(mini_max_algorithm.scores)
        print("The best score for {} is {}".format("Maximizer" if is_maximizer else "Minimizer", best_score))

    def mini_max(self, depth, is_maximizer, index, verbose):
        best_score = 0
        score1 = 0
        score2 = 0

        if depth == self.height:  # Leaf node reached.
            return self.scores[index]

        score1 = self.mini_max(depth + 1, not is_maximizer, index * 2, verbose)
        score2 = self.mini_max(depth + 1, not is_maximizer, index * 2 + 1, verbose)

        if is_maximizer:
            # Maximizer player wants to get the maximum possible score.
            best_score = max(score1, score2)
        else:
            # Minimizer player wants to get the minimum possible score.
            best_score = min(score1, score2)

        if verbose:
            print(f"From {score1} and {score2}, {'Maximizer' if is_maximizer else 'Minimizer'} chooses {best_score}")

        return best_score

    def log2(self, n):
        return 0 if n == 1 else self.log2(n // 2) + 1

    def get_scores(self):
        return self.scores

