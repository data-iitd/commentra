import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = self.log2(len(scores))

    def mini_max(self, depth, is_maximizer, index, verbose):
        if depth == self.height:
            return self.scores[index]
        
        score1 = self.mini_max(depth + 1, not is_maximizer, index * 2, verbose)
        score2 = self.mini_max(depth + 1, not is_maximizer, (index * 2) + 1, verbose)
        
        if is_maximizer:
            best_score = max(score1, score2)
        else:
            best_score = min(score1, score2)
        
        if verbose:
            print(f"From {score1:02d} and {score2:02d}, {'Maximizer' if is_maximizer else 'Minimizer'} chooses {best_score:02d}")
        
        return best_score

    def log2(self, n):
        return 0 if n == 1 else self.log2(n // 2) + 1

    def get_scores(self):
        return self.scores

if __name__ == "__main__":
    num_leaf_nodes = int(input())
    if (num_leaf_nodes & (num_leaf_nodes - 1)) != 0:
        print("Error: The number of leaf nodes must be a power of 2.")
    else:
        scores = [int(input()) for _ in range(num_leaf_nodes)]
        mini_max_algorithm = Main(scores)
        is_maximizer = input().strip().lower() == 'true'
        verbose = True
        best_score = mini_max_algorithm.mini_max(0, is_maximizer, 0, verbose)
        print(mini_max_algorithm.get_scores())
        print(f"The best score for {'Maximizer' if is_maximizer else 'Minimizer'} is {best_score}")

# <END-OF-CODE>
