import random
import time
from typing import List, Optional

class Node:
    def __init__(self, parent: Optional['Node'], is_players_turn: bool):
        self.parent = parent
        self.child_nodes: List[Node] = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

class MonteCarloTreeSearch:
    WIN_SCORE = 10
    TIME_LIMIT = 0.5  # in seconds

    def monte_carlo_tree_search(self, root_node: Node, child_count: int) -> Node:
        winner_node = None
        time_limit = time.time() + self.TIME_LIMIT

        # Add child nodes to the root node
        self.add_child_nodes(root_node, child_count)

        # Search for the promising node within the time limit
        while time.time() < time_limit:
            promising_node = self.get_promising_node(root_node)

            # If there are no child nodes for the promising node, add them
            if not promising_node.child_nodes:
                self.add_child_nodes(promising_node, child_count)

            # Simulate random play for the promising node
            self.simulate_random_play(promising_node)

        # Find the winning node
        winner_node = self.get_winner_node(root_node)

        # Print the scores for all nodes in the tree
        self.print_scores(root_node)

        return winner_node

    def add_child_nodes(self, node: Node, child_count: int):
        for _ in range(child_count):
            node.child_nodes.append(Node(node, not node.is_players_turn))

    def get_promising_node(self, root_node: Node) -> Node:
        promising_node = root_node

        # Traverse the tree to find the promising node
        while promising_node.child_nodes:
            max_uct = float('-inf')
            best_child_node = None

            # Find the child node with the highest UCT value
            for child_node in promising_node.child_nodes:
                uct_value = (child_node.visit_count == 0) * float('inf') or (
                    (child_node.score / child_node.visit_count) +
                    1.41 * ( (promising_node.visit_count ** 0.5) / (child_node.visit_count ** 0.5) )
                )

                # Update the best child node if the UCT value is higher
                if uct_value > max_uct:
                    max_uct = uct_value
                    best_child_node = child_node

            # Update the promising node to the best child node
            promising_node = best_child_node

        return promising_node

    def simulate_random_play(self, promising_node: Node):
        current_node = promising_node

        # Simulate the game by following the tree until reaching the root node
        while current_node is not None:
            current_node.visit_count += 1

            # Update the score if the player wins or loses
            if (current_node.is_players_turn and random.choice([True, False])) or \
               (not current_node.is_players_turn and not random.choice([True, False])):
                current_node.score += self.WIN_SCORE

            current_node = current_node.parent

    def get_winner_node(self, root_node: Node) -> Node:
        return max(root_node.child_nodes, key=lambda c: c.score)

    def print_scores(self, root_node: Node):
        print("Node\tScore\tVisits")
        for index, node in enumerate(root_node.child_nodes):
            print(f"{index + 1}\t{node.score}\t{node.visit_count}")

if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = input().strip().lower() == 'true'

    mcts = MonteCarloTreeSearch()
    root_node = Node(None, is_players_turn)

    # Perform Monte Carlo Tree Search and find the winning node
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)

    # Print the index of the winning node
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")

# <END-OF-CODE>
