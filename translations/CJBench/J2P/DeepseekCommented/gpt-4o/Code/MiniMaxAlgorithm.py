import math

class Main:
    def __init__(self, scores):
        self.scores = scores
        self.height = self.log2(len(scores))

    @staticmethod
    def main(args):
        scanner = Scanner(input())
        num_leaf_nodes = int(scanner.next())

        # Check if the number of leaf nodes is a power of 2
        if (num_leaf_nodes & (num_leaf_nodes - 1)) != 0:
            print("Error: The number of leaf nodes must be a power of 2.")
            return

        # Read the scores of the leaf nodes from the user
        scores = [int(scanner.next()) for _ in range(num_leaf_nodes)]

        # Create an instance of the Main class with the scores array
        mini_max_algorithm = Main(scores)
        is_maximizer = scanner.nextBoolean()
        verbose = True

        # Run the MiniMax algorithm to find the best score
        best_score = mini_max_algorithm.miniMax(0, is_maximizer, 0, verbose)

        # Print the scores array and the best score for the player
        print(mini_max_algorithm.get_scores())
        print("The best score for {} is {}".format("Maximizer" if is_maximizer else "Minimizer", best_score))

    def miniMax(self, depth, is_maximizer, index, verbose):
        best_score = 0
        score1 = 0
        score2 = 0

        # Base case: when depth equals the height of the tree
        if depth == self.height:
            return self.scores[index]

        # Recursively evaluate the scores for the left and right children
        score1 = self.miniMax(depth + 1, not is_maximizer, index * 2, verbose)
        score2 = self.miniMax(depth + 1, not is_maximizer, index * 2 + 1, verbose)

        # Determine the best score based on whether it's the Maximizer or Minimizer's turn
        if is_maximizer:
            best_score = max(score1, score2)
        else:
            best_score = min(score1, score2)

        # Print the choice if verbose mode is enabled
        if verbose:
            print("From {} and {}, {} chooses {}".format(score1, score2, "Maximizer" if is_maximizer else "Minimizer", best_score))

        return best_score

    def log2(self, n):
        return 0 if n == 1 else self.log2(n // 2) + 1

    def get_scores(self):
        return self.scores

