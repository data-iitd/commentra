
import random
import time

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.childNodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

WIN_SCORE = 10
TIME_LIMIT = 500

def monte_carlo_tree_search(root_node, child_count):
    winner_node = None
    time_limit = time.time() + TIME_LIMIT

    while time.time() < time_limit:
        promising_node = get_promising_node(root_node)
        if not promising_node.childNodes:
            add_child_nodes(promising_node, child_count)
        simulate_random_play(promising_node)

    winner_node = get_winner_node(root_node)
    print_scores(root_node)
    return winner_node

def add_child_nodes(node, child_count):
    for _ in range(child_count):
        node.childNodes.append(Node(node, not node.is_players_turn))

def get_promising_node(root_node):
    promising_node = root_node
    while promising_node.childNodes:
        uct_index = float('-inf')
        node_index = 0
        for i, child_node in enumerate(promising_node.childNodes):
            uct_temp = (child_node.visit_count == 0) and float('inf') or (child_node.score / child_node.visit_count) + 1.41 * (math.log(promising_node.visit_count) / child_node.visit_count)
            if uct_temp > uct_index:
                uct_index = uct_temp
                node_index = i
        promising_node = promising_node.childNodes[node_index]
    return promising_node

def simulate_random_play(promising_node):
    rand = random.Random()
    temp_node = promising_node
    is_player_winner = rand.random() < 0.5

    while temp_node:
        temp_node.visit_count += 1
        if (temp_node.is_players_turn and is_player_winner) or (not temp_node.is_players_turn and not is_player_winner):
            temp_node.score += WIN_SCORE
        temp_node = temp_node.parent

def get_winner_node(root_node):
    return max(root_node.childNodes, key=lambda c: c.score)

def print_scores(root_node):
    print("Node\tScore\tVisits")
    for i, child_node in enumerate(root_node.childNodes):
        print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = bool(input())
    root_node = Node(None, is_players_turn)
    winner_node = monte_carlo_tree_search(root_node, child_count)
    print(f"Optimal node: {root_node.childNodes.index(winner_node) + 1}")