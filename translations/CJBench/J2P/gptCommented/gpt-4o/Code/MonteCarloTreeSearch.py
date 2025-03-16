import random
import time
from typing import List, Optional

class Node:
    def __init__(self, parent: Optional['Node'], is_players_turn: bool):
        self.parent = parent  # Reference to the parent node
        self.child_nodes: List[Node] = []  # List of child nodes
        self.is_players_turn = is_players_turn  # Indicates if it's the player's turn
        self.player_won = False  # Indicates if the player has won
        self.score = 0  # Score for the node
        self.visit_count = 0  # Number of times the node has been visited

class MonteCarloTreeSearch:
    WIN_SCORE = 10  # Score awarded for a win
    TIME_LIMIT = 0.5  # Time limit for the Monte Carlo simulation in seconds

    def monte_carlo_tree_search(self, root_node: Node, child_count: int) -> Node:
        # Generate child nodes for the root node
        self.add_child_nodes(root_node, child_count)
        time_limit = time.time() + self.TIME_LIMIT  # Set the time limit

        # Run the simulation until the time limit is reached
        while time.time() < time_limit:
            promising_node = self.get_promising_node(root_node)  # Get a promising node to explore
            # If the promising node has no child nodes, add them
            if not promising_node.child_nodes:
                self.add_child_nodes(promising_node, child_count)
            # Simulate a random play from the promising node
            self.simulate_random_play(promising_node)

        # Determine the winning node based on scores
        winner_node = self.get_winner_node(root_node)
        # Print the scores of all child nodes
        self.print_scores(root_node)
        return winner_node  # Return the winning node

    def add_child_nodes(self, node: Node, child_count: int):
        for _ in range(child_count):
            # Create a new child node with the opposite player's turn
            node.child_nodes.append(Node(node, not node.is_players_turn))

    def get_promising_node(self, root_node: Node) -> Node:
        promising_node = root_node  # Start with the root node
        # Traverse down the tree until a node with no children is found
        while promising_node.child_nodes:
            uct_index = float('-inf')  # Initialize UCT index
            node_index = 0  # Index of the best child node

            # Evaluate each child node to find the one with the highest UCT value
            for i, child_node in enumerate(promising_node.child_nodes):
                uct_temp = (child_node.visit_count == 0) \
                    and float('inf') or (child_node.score / child_node.visit_count) \
                    + 1.41 * ( (promising_node.visit_count ** 0.5) / (child_node.visit_count ** 0.5) )

                # Update the best child node if the current one has a higher UCT
                if uct_temp > uct_index:
                    uct_index = uct_temp
                    node_index = i
            # Move to the selected promising child node
            promising_node = promising_node.child_nodes[node_index]
        return promising_node  # Return the most promising node

    def simulate_random_play(self, promising_node: Node):
        temp_node = promising_node  # Start from the promising node
        is_player_winner = random.choice([True, False])  # Randomly determine the winner

        # Backpropagate the results up the tree
        while temp_node is not None:
            temp_node.visit_count += 1  # Increment visit count for the node
            # Update score based on whether the player won
            if (temp_node.is_players_turn and is_player_winner) or (not temp_node.is_players_turn and not is_player_winner):
                temp_node.score += self.WIN_SCORE  # Award score for a win
            temp_node = temp_node.parent  # Move up to the parent node

    def get_winner_node(self, root_node: Node) -> Node:
        return max(root_node.child_nodes, key=lambda c: c.score)  # Return the node with the maximum score

    def print_scores(self, root_node: Node):
        print("Node\tScore\tVisits")  # Print header
        for i, child_node in enumerate(root_node.child_nodes):
            # Print the index, score, and visit count for each child node
            print(f"{i + 1}\t{child_node.score}\t{child_node.visit_count}")

# Main method to execute the program
if __name__ == "__main__":
    child_count = int(input("Enter the number of child nodes to generate: "))  # Read the number of child nodes to generate
    is_players_turn = input("Is it the player's turn? (True/False): ").strip().lower() == 'true'  # Read whose turn it is
    mcts = MonteCarloTreeSearch()  # Create an instance of the Monte Carlo Tree Search class
    root_node = Node(None, is_players_turn)  # Create the root node
    winner_node = mcts.monte_carlo_tree_search(root_node, child_count)  # Perform Monte Carlo Tree Search
    # Print the index of the optimal node
    print(f"Optimal node: {root_node.child_nodes.index(winner_node) + 1}")
