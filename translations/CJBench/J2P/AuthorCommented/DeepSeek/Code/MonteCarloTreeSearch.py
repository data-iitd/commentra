import random
import math
from collections import defaultdict

class Node:
    def __init__(self, parent=None, is_players_turn=True):
        self.parent = parent
        self.children = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

WIN_SCORE = 10
TIME_LIMIT = 500  # Time the algorithm will be running for (in milliseconds).

class MCTS:
    def __init__(self):
        pass

    def monte_carlo_tree_search(self, root_node, child_count):
        winner_node = None
        time_limit = int(time.time() * 1000) + TIME_LIMIT

        # Expand the root node with a given number of children.
        self.add_child_nodes(root_node, child_count)

        # Explore the tree until the time limit is reached.
        while int(time.time() * 1000) < time_limit:
            promising_node = self.get_promising_node(root_node)

            # Expand the promising node.
            if not promising_node.children:
                self.add_child_nodes(promising_node, child_count)

            self.simulate_random_play(promising_node)

        winner_node = self.get_winner_node(root_node)
        self.print_scores(root_node)

        return winner_node

    def add_child_nodes(self, node, child_count):
        for _ in range(child_count):
            node.children.append(Node(node, not node.is_players_turn))

    def get_promising_node(self, root_node):
        promising_node = root_node

        # Iterate until a node that hasn't been expanded is found.
        while root_node.children:
            uct_index = -float('inf')
            node_index = 0

            # Iterate through child nodes and pick the most promising one
            # using UCT (Upper Confidence bounds applied to Trees).
            for i, child_node in enumerate(root_node.children):
                uct_temp = (child_node.visit_count == 0) \
                           and float('inf') \
                           or (child_node.score / child_node.visit_count) \
                           + 1.41 * math.sqrt(math.log(root_node.visit_count) / child_node.visit_count)

                if uct_temp > uct_index:
                    uct_index = uct_temp
                    node_index = i

            promising_node = root_node.children[node_index]

        return promising_node

    def simulate_random_play(self, promising_node):
        temp_node = promising_node
        is_player_winner = random.choice([True, False])  # Random outcome for demonstration.

        while temp_node:
            temp_node.visit_count += 1

            if (temp_node.is_players_turn and is_player_winner) or (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += WIN_SCORE

            temp_node = temp_node.parent

    def get_winner_node(self, root_node):
        return max(root_node.children, key=lambda c: c.score)

    def print_scores(self, root_node):
        print("Node\tScore\tVisits")
        for i, child_node in enumerate(root_node.children):
            print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

if __name__ == "__main__":
    import time
    import sys

    # Input: Number of children for the root node
    child_count = int(sys.stdin.readline().strip())

    # Input: Is it the player's turn at the root node
    is_players_turn = sys.stdin.readline().strip() == 'True'

    # Run Monte Carlo Tree Search
    mcts = MCTS()
    root_node = Node(None, is_players_turn)
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)

    # Output: Optimal node index
    print(f"Optimal node: {root_node.children.index(winner_node) + 1}")
