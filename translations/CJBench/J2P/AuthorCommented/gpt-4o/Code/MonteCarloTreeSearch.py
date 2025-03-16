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
    TIME_LIMIT = 0.5  # Time the algorithm will be running for (in seconds).

    def monte_carlo_tree_search(self, root_node: Node, child_count: int) -> Node:
        # Expand the root node with a given number of children.
        self.add_child_nodes(root_node, child_count)

        time_limit = time.time() + self.TIME_LIMIT

        # Explore the tree until the time limit is reached.
        while time.time() < time_limit:
            promising_node = self.get_promising_node(root_node)

            # Expand the promising node.
            if not promising_node.child_nodes:
                self.add_child_nodes(promising_node, child_count)

            self.simulate_random_play(promising_node)

        winner_node = self.get_winner_node(root_node)
        self.print_scores(root_node)

        return winner_node

    def add_child_nodes(self, node: Node, child_count: int):
        for _ in range(child_count):
            node.child_nodes.append(Node(node, not node.is_players_turn))

    def get_promising_node(self, root_node: Node) -> Node:
        promising_node = root_node

        # Iterate until a node that hasn't been expanded is found.
        while promising_node.child_nodes:
            uct_index = float('-inf')
            node_index = 0

            # Iterate through child nodes and pick the most promising one using UCT.
            for i, child_node in enumerate(promising_node.child_nodes):
                uct_temp = (child_node.visit_count == 0) \
                    and float('inf') \
                    or (child_node.score / child_node.visit_count) + \
                    1.41 * ( (promising_node.visit_count ** 0.5) / (child_node.visit_count ** 0.5) )

                if uct_temp > uct_index:
                    uct_index = uct_temp
                    node_index = i

            promising_node = promising_node.child_nodes[node_index]

        return promising_node

    def simulate_random_play(self, promising_node: Node):
        temp_node = promising_node
        is_player_winner = random.choice([True, False])  # Random outcome for demonstration.

        while temp_node is not None:
            temp_node.visit_count += 1

            if (temp_node.is_players_turn and is_player_winner) or \
               (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += self.WIN_SCORE

            temp_node = temp_node.parent

    def get_winner_node(self, root_node: Node) -> Node:
        return max(root_node.child_nodes, key=lambda c: c.score)

    def print_scores(self, root_node: Node):
        print("Node\tScore\tVisits")
        for i, child in enumerate(root_node.child_nodes):
            print(f"{i + 1}\t{child.score}\t{child.visit_count}")

if __name__ == "__main__":
    # Input: Number of children for the root node
    child_count = int(input())

    # Input: Is it the player's turn at the root node
    is_players_turn = input().strip().lower() == 'true'

    # Run Monte Carlo Tree Search
    mcts = MonteCarloTreeSearch()
    root_node = Node(None, is_players_turn)
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)

    # Output: Optimal node index
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")

# <END-OF-CODE>
