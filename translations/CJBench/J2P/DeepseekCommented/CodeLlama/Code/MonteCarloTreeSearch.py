import random

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.child_nodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0

def monte_carlo_tree_search(root_node, child_count):
    winner_node = None
    time_limit = 500
    while time_limit > 0:
        promising_node = get_promising_node(root_node)
        if promising_node.child_nodes == []:
            add_child_nodes(promising_node, child_count)
        simulate_random_play(promising_node)
        time_limit -= 1
    winner_node = get_winner_node(root_node)
    print_scores(root_node)
    return winner_node

def add_child_nodes(node, child_count):
    for i in range(child_count):
        node.child_nodes.append(Node(node, not node.is_players_turn))

def get_promising_node(root_node):
    promising_node = root_node
    while promising_node.child_nodes != []:
        uct_index = float('-inf')
        node_index = 0
        for i in range(len(promising_node.child_nodes)):
            child_node = promising_node.child_nodes[i]
            uct_temp = (child_node.visit_count == 0) \
                * float('inf') \
                + (child_node.score / child_node.visit_count) \
                + 1.41 * math.sqrt(math.log(root_node.visit_count) / child_node.visit_count)
            if uct_temp > uct_index:
                uct_index = uct_temp
                node_index = i
        promising_node = promising_node.child_nodes[node_index]
    return promising_node

def simulate_random_play(promising_node):
    rand = random.Random()
    temp_node = promising_node
    is_player_winner = rand.random() > 0.5
    while temp_node != None:
        temp_node.visit_count += 1
        if (temp_node.is_players_turn and is_player_winner) or (not temp_node.is_players_turn and not is_player_winner):
            temp_node.score += 10
        temp_node = temp_node.parent

def get_winner_node(root_node):
    return max(root_node.child_nodes, key=lambda c: c.score)

def print_scores(root_node):
    print("Node\tScore\tVisits")
    for i in range(len(root_node.child_nodes)):
        print(f"{i+1}\t{root_node.child_nodes[i].score}\t{root_node.child_nodes[i].visit_count}")

if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = bool(input())
    root_node = Node(None, is_players_turn)
    winner_node = monte_carlo_tree_search(root_node, child_count)
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")

