import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = self.log2(len(scores))  # Calculate height of tree based on number of scores

    @staticmethod
    def log2(n):
        return 0 if n == 1 else 1 + Main.log2(n // 2)

    def mini_max(self, depth, is_maximizer, index, verbose):
        # Base case: leaf node
        if depth == self.height:
            return self.scores[index]

        # Recursive call for minimizing player
        score1 = self.mini_max(depth + 1, not is_maximizer, index * 2, verbose)

        # Recursive call for maximizing player
        score2 = self.mini_max(depth + 1, not is_maximizer, (index * 2) + 1, verbose)

        # Determine best score based on whether maximizing or minimizing
        if is_maximizer:
            best_score = max(score1, score2)
        else:
            best_score = min(score1, score2)

        # Print verbose output if enabled
        if verbose:
            print(f"From {score1:02d} and {score2:02d}, {'Maximizer' if is_maximizer else 'Minimizer'} chooses {best_score:02d}")

        return best_score

    def get_scores(self):
        return self.scores


if __name__ == "__main__":
    num_leaf_nodes = int(input("Enter number of leaf nodes: "))
    if (num_leaf_nodes & (num_leaf_nodes - 1)) != 0:  # Check if number is power of 2 using bitwise AND
        print("Error: The number of leaf nodes must be a power of 2.")
    else:
        scores = [int(input("Enter score: ")) for _ in range(num_leaf_nodes)]  # Read scores from user

        # Initialize MiniMax algorithm
        mini_max_algorithm = Main(scores)

        # Read whether it's maximizer or minimizer turn
        is_maximizer = input("Is it Maximizer's turn? (True/False): ").strip().lower() == 'true'

        # Read whether to be verbose or not
        verbose = True

        # Run MiniMax algorithm and print results
        best_score = mini_max_algorithm.mini_max(0, is_maximizer, 0, verbose)
        print(f"Scores: {mini_max_algorithm.get_scores()}")
        print(f"The best score for {'Maximizer' if is_maximizer else 'Minimizer'} is {best_score}")

# <END-OF-CODE>
