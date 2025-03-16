

import random

class Node:
    def __init__(self, parent, is_players_turn):
        self.parent = parent
        self.child_nodes = []
        self.is_players_turn = is_players_turn
        self.player_won = False
        self.score = 0
        self.visit_count = 0


class MonteCarloTreeSearch:
    def __init__(self):
        self.root_node = None

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
                    * float('inf') \
                    if child_node.visit_count == 0 \
                    else (child_node.score / child_node.visit_count) \
                    + 1.41 * (math.log(promising_node.visit_count) / child_node.visit_count)

                if uct_temp > uct_index:
                    uct_index = uct_temp
                    node_index = i

            promising_node = promising_node.child_nodes[node_index]

        return promising_node

    def simulate_random_play(self, promising_node):
        random_outcome = random.choice([True, False])

        temp_node = promising_node

        while temp_node is not None:
            temp_node.visit_count += 1

            if (temp_node.is_players_turn and random_outcome) or (not temp_node.is_players_turn and not random_outcome):
                temp_node.score += 10

            temp_node = temp_node.parent

    def get_winner_node(self, root_node):
        return max(root_node.child_nodes, key=lambda c: c.score)

    def print_scores(self, root_node):
        print("Node\tScore\tVisits")
        for i, child_node in enumerate(root_node.child_nodes):
            print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

    def run(self, child_count, is_players_turn):
        self.root_node = Node(None, is_players_turn)
        self.add_child_nodes(self.root_node, child_count)

        time_limit = time.time() + 500

        while time.time() < time_limit:
            promising_node = self.get_promising_node(self.root_node)

            if not promising_node.child_nodes:
                self.add_child_nodes(promising_node, child_count)

            self.simulate_random_play(promising_node)

        winner_node = self.get_winner_node(self.root_node)
        self.print_scores(self.root_node)

        return winner_node


if __name__ == "__main__":
    child_count = int(input())
    is_players_turn = bool(input())

    mcts = MonteCarloTreeSearch()
    winner_node = mcts.run(child_count, is_players_turn)

    print(f"Optimal node: {mcts.root_node.child_nodes.index(winner_node) + 1}")

