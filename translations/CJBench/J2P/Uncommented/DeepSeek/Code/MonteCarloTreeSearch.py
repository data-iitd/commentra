import random
import math
from collections import defaultdict

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.children = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

class MCTS:
    WIN_SCORE = 10
    TIME_LIMIT = 500

    def monte_carlo_tree_search(self, root_node, child_count):
        self.add_child_nodes(root_node, child_count)
        time_limit = int(time.time() * 1000) + self.TIME_LIMIT
        while int(time.time() * 1000) < time_limit:
            promising_node = self.get_promising_node(root_node)
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
        while root_node.children:
            uct_index = -float('inf')
            node_index = 0
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
        is_player_winner = random.choice([True, False])
        while temp_node:
            temp_node.visit_count += 1
            if (temp_node.is_players_turn and is_player_winner) or (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += self.WIN_SCORE
            temp_node = temp_node.parent

    def get_winner_node(self, root_node):
        return max(root_node.children, key=lambda c: c.score)

    def print_scores(self, root_node):
        print("Node\tScore\tVisits")
        for i, child_node in enumerate(root_node.children):
            print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = input().strip() == 'True'
    mcts = MCTS()
    root_node = Node(None, is_players_turn)
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)
    print(f"Optimal node: {root_node.children.index(winner_node) + 1}")
