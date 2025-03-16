

import random
import sys

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.child_nodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

WIN_SCORE = 10
TIME_LIMIT = 500  # Time the algorithm will be running for (in milliseconds).

def monte_carlo_tree_search(root_node, child_count):
    winner_node = None
    time_limit = int(round(time.time() * 1000)) + TIME_LIMIT

    # Expand the root node with a given number of children.
    add_child_nodes(root_node, child_count)

    while int(round(time.time() * 1000)) < time_limit:
        promising_node = get_promising_node(root_node)

        # Expand the promising node.
        if not promising_node.child_nodes:
            add_child_nodes(promising_node, child_count)

        simulate_random_play(promising_node)

    winner_node = get_winner_node(root_node)
    print_scores(root_node)

    return winner_node

def add_child_nodes(node, child_count):
    for _ in range(child_count):
        node.child_nodes.append(Node(node, not node.is_players_turn))

def get_promising_node(root_node):
    promising_node = root_node

    # Iterate until a node that hasn't been expanded is found.
    while promising_node.child_nodes:
        uct_index = -sys.maxsize
        node_index = 0

        # Iterate through child nodes and pick the most promising one
        # using UCT (Upper Confidence bounds applied to Trees).
        for i, child_node in enumerate(promising_node.child_nodes):
            uct_temp = (child_node.visit_count == 0) and sys.maxsize or (child_node.score / child_node.visit_count) + 1.41 * math.sqrt(math.log(promising_node.visit_count) / child_node.visit_count)

            if uct_temp > uct_index:
                uct_index = uct_temp
                node_index = i

        promising_node = promising_node.child_nodes[node_index]

    return promising_node

def simulate_random_play(promising_node):
    is_player_winner = random.choice([True, False])  # Random outcome for demonstration.

    while promising_node:
        promising_node.visit_count += 1

        if (promising_node.is_players_turn and is_player_winner) or (not promising_node.is_players_turn and not is_player_winner):
            promising_node.score += WIN_SCORE

        promising_node = promising_node.parent

def get_winner_node(root_node):
    return max(root_node.child_nodes, key=lambda c: c.score)

def print_scores(root_node):
    print("Node\tScore\tVisits")
    for i, child_node in enumerate(root_node.child_nodes):
        print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

if __name__ == "__main__":
    child_count = int(input())  # Input: Number of children for the root node
    is_players_turn = bool(input())  # Input: Is it the player's turn at the root node

    # Run Monte Carlo Tree Search
    root_node = Node(None, is_players_turn)
    winner_node = monte_carlo_tree_search(root_node, child_count)

    # Output: Optimal node index
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")