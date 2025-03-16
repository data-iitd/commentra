
import random

# Define a custom Node class for the tree
class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.child_nodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

# Constants for the game
WIN_SCORE = 10
TIME_LIMIT = 500

# Main method for Monte Carlo Tree Search
def monte_carlo_tree_search(root_node, child_count):
    winner_node = None
    time_limit = time.time() + TIME_LIMIT

    # Add child nodes to the root node
    add_child_nodes(root_node, child_count)

    # Search for the promising node within the time limit
    while time.time() < time_limit:
        promising_node = get_promising_node(root_node)

        # If there are no child nodes for the promising node, add them
        if not promising_node.child_nodes:
            add_child_nodes(promising_node, child_count)

        # Simulate random play for the promising node
        simulate_random_play(promising_node)

    # Find the winning node
    winner_node = get_winner_node(root_node)

    # Print the scores for all nodes in the tree
    print_scores(root_node)

    return winner_node

# Add child nodes to the given node
def add_child_nodes(node, child_count):
    for _ in range(child_count):
        node.child_nodes.append(Node(node, not node.is_players_turn))

# Find the promising node based on UCT (Upper Confidence Bound)
def get_promising_node(root_node):
    promising_node = root_node

    # Traverse the tree to find the promising node
    while promising_node.child_nodes:
        max_uct = float('-inf')
        best_child_node = None

        # Find the child node with the highest UCT value
        for child_node in promising_node.child_nodes:
            uct_value = (child_node.visit_count == 0) \
                        * float('inf') \
                        + (child_node.visit_count > 0) \
                        * ((child_node.score / child_node.visit_count) \
                        + 1.41 * math.sqrt(math.log(promising_node.visit_count) / child_node.visit_count))

            # Update the best child node if the UCT value is higher
            if uct_value > max_uct:
                max_uct = uct_value
                best_child_node = child_node

        # Update the promising node to the best child node
        promising_node = best_child_node

    return promising_node

# Simulate random play for the given node
def simulate_random_play(promising_node):
    random.seed()
    current_node = promising_node

    # Simulate the game by following the tree until reaching the root node
    while current_node is not None:
        current_node.visit_count += 1

        # Update the score if the player wins or loses
        if (current_node.is_players_turn and random.random() < 0.5) or (not current_node.is_players_turn and random.random() >= 0.5):
            current_node.score += WIN_SCORE

        current_node = current_node.parent

# Find the winning node with the highest score
def get_winner_node(root_node):
    return max(root_node.child_nodes, key=lambda c: c.score)

# Print the scores and visits for all nodes in the tree
def print_scores(root_node):
    print("Node\tScore\tVisits")

    # Traverse the tree and print the scores and visits for each node
    for node in root_node.child_nodes:
        print(f"{node.index + 1}\t{node.score}\t{node.visit_count}")

# Main method for running the Monte Carlo Tree Search algorithm
def main():
    child_count = int(input())
    is_players_turn = bool(input())

    root_node = Node(None, is_players_turn)

    # Perform Monte Carlo Tree Search and find the winning node
    winner_node = monte_carlo_tree_search(root_node, child_count)

    # Print the index of the winning node
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")

if __name__ == "__main__":
    main()

