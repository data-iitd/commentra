

import random
import sys
import time
WIN_SCORE = 10
TIME_LIMIT = 500
class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.childNodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0
    def add_child_nodes(self, child_count):
        for _ in range(child_count):
            self.childNodes.append(Node(self, not self.is_players_turn))
    def get_promising_node(self):
        promising_node = self
        while promising_node.childNodes:
            uct_index = -float('inf')
            node_index = 0
            for i, child_node in enumerate(promising_node.childNodes):
                uct_temp = (child_node.visit_count == 0) \
                    and float('inf') or (child_node.score / child_node.visit_count) \
                    + 1.41 * (math.log(promising_node.visit_count) / child_node.visit_count)
                if uct_temp > uct_index:
                    uct_index = uct_temp
                    node_index = i
            promising_node = promising_node.childNodes[node_index]
        return promising_node
    def simulate_random_play(self):
        rand = random.Random()
        temp_node = self
        is_player_winner = rand.random() < 0.5
        while temp_node:
            temp_node.visit_count += 1
            if (temp_node.is_players_turn and is_player_winner) \
                or (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += WIN_SCORE
            temp_node = temp_node.parent
    def get_winner_node(self):
        return max(self.childNodes, key=lambda c: c.score)
    def print_scores(self):
        print("Node\tScore\tVisits")
        for i, child_node in enumerate(self.childNodes):
            print("{}\t{}\t{}".format(i + 1, child_node.score, child_node.visit_count))
def monte_carlo_tree_search(root_node, child_count):
    winner_node = None
    time_limit = time.time() + TIME_LIMIT
    root_node.add_child_nodes(child_count)
    while time.time() < time_limit:
        promising_node = root_node.get_promising_node()
        if not promising_node.childNodes:
            promising_node.add_child_nodes(child_count)
        promising_node.simulate_random_play()
    winner_node = root_node.get_winner_node()
    winner_node.print_scores()
    return winner_node
if __name__ == '__main__':
    child_count = int(input())
    is_players_turn = bool(int(input()))
    root_node = Node(None, is_players_turn)
    winner_node = monte_carlo_tree_search(root_node, child_count)
    print("Optimal node: {}".format(root_node.childNodes.index(winner_node) + 1))
