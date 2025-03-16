import random
import time
from collections import namedtuple

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.child_nodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

class MonteCarloTreeSearch:
    WIN_SCORE = 10
    TIME_LIMIT = 0.5  # 500 milliseconds

    def monte_carlo_tree_search(self, root_node, child_count):
        self.add_child_nodes(root_node, child_count)
        time_limit = time.time() + self.TIME_LIMIT
        while time.time() < time_limit:
            promising_node = self.get_promising_node(root_node)
            if not promising_node.child_nodes:
                self.add_child_nodes(promising_node, child_count)
            self.simulate_random_play(promising_node)
        winner_node = self.get_winner_node(root_node)
        self.print_scores(root_node)
        return winner_node

    def add_child_nodes(self, node, child_count):
        for _ in range(child_count):
            node.child_nodes.append(Node(node, not node.is_players_turn))

    def get_promising_node(self, root_node):
        promising_node = root_node
        while promising_node.child_nodes:
            uct_index = float('-inf')
            node_index = 0
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

    def simulate_random_play(self, promising_node):
        temp_node = promising_node
        is_player_winner = random.choice([True, False])
        while temp_node is not None:
            temp_node.visit_count += 1
            if (temp_node.is_players_turn and is_player_winner) or \
               (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += self.WIN_SCORE
            temp_node = temp_node.parent

    def get_winner_node(self, root_node):
        return max(root_node.child_nodes, key=lambda c: c.score)

    def print_scores(self, root_node):
        print("Node\tScore\tVisits")
        for i, child_node in enumerate(root_node.child_nodes):
            print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = input().lower() == 'true'
    mcts = MonteCarloTreeSearch()
    root_node = Node(None, is_players_turn)
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")

# <END-OF-CODE>
