import random
import math

# Node class representing each state in the game tree
class Node:
    def __init__(self, parent, isPlayersTurn):
        self.parent = parent
        self.childNodes = []
        self.isPlayersTurn = isPlayersTurn
        self.playerWon = False
        self.score = 0
        self.visitCount = 0

# Constants for scoring and time limits
WIN_SCORE = 10
TIME_LIMIT = 500

# Main function to perform Monte Carlo Tree Search
def monteCarloTreeSearch(rootNode, childCount):
    winnerNode = None
    timeLimit = time.time() + TIME_LIMIT

    # Generate child nodes for the root node
    addChildNodes(rootNode, childCount)

    # Run the simulation until the time limit is reached
    while time.time() < timeLimit:
        promisingNode = getPromisingNode(rootNode) # Get a promising node to explore
        # If the promising node has no child nodes, add them
        if len(promisingNode.childNodes) == 0:
            addChildNodes(promisingNode, childCount)
        # Simulate a random play from the promising node
        simulateRandomPlay(promisingNode)

    # Determine the winning node based on scores
    winnerNode = getWinnerNode(rootNode)
    # Print the scores of all child nodes
    printScores(rootNode)
    return winnerNode # Return the winning node

# Method to add child nodes to a given node
def addChildNodes(node, childCount):
    for i in range(childCount):
        # Create a new child node with the opposite player's turn
        node.childNodes.append(Node(node, not node.isPlayersTurn))

# Method to get the most promising node based on UCT (Upper Confidence Bound for Trees)
def getPromisingNode(rootNode):
    promisingNode = rootNode # Start with the root node
    # Traverse down the tree until a node with no children is found
    while len(promisingNode.childNodes) > 0:
        uctIndex = float("-inf") # Initialize UCT index
        nodeIndex = 0 # Index of the best child node

        # Evaluate each child node to find the one with the highest UCT value
        for i in range(len(promisingNode.childNodes)):
            childNode = promisingNode.childNodes[i]
            uctTemp = (childNode.visitCount == 0) \
               ? float("inf") # If the child has not been visited, prioritize it
                : ((childNode.score / childNode.visitCount) \
                    + 1.41 * math.sqrt(math.log(promisingNode.visitCount) / childNode.visitCount)) # Calculate UCT

            # Update the best child node if the current one has a higher UCT
            if uctTemp > uctIndex:
                uctIndex = uctTemp
                nodeIndex = i

        # Move to the selected promising child node
        promisingNode = promisingNode.childNodes[nodeIndex]
    return promisingNode # Return the most promising node

# Method to simulate a random play from a given node
def simulateRandomPlay(promisingNode):
    rand = random.Random() # Random number generator
    tempNode = promisingNode # Start from the promising node
    isPlayerWinner = rand.choice([True, False]) # Randomly determine the winner

    # Backpropagate the results up the tree
    while tempNode!= None:
        tempNode.visitCount += 1 # Increment visit count for the node
        # Update score based on whether the player won
        if (tempNode.isPlayersTurn and isPlayerWinner) or (not tempNode.isPlayersTurn and not isPlayerWinner):
            tempNode.score += WIN_SCORE # Award score for a win
        tempNode = tempNode.parent # Move up to the parent node

# Method to get the child node with the highest score
def getWinnerNode(rootNode):
    return max(rootNode.childNodes, key = lambda c: c.score) # Return the node with the maximum score

# Method to print the scores and visit counts of all child nodes
def printScores(rootNode):
    print("Node\tScore\tVisits") # Print header
    for i in range(len(rootNode.childNodes)):
        # Print the index, score, and visit count for each child node
        print("%d\t%d\t%d" % (i + 1, rootNode.childNodes[i].score, rootNode.childNodes[i].visitCount))

# Main method to execute the program
if __name__ == "__main__":
    childCount = int(input()) # Read the number of child nodes to generate
    isPlayersTurn = input().lower() == "true" # Read whose turn it is
    mcts = Main() # Create an instance of the Main class
    rootNode = mcts.Node(None, isPlayersTurn) # Create the root node
    winnerNode = monteCarloTreeSearch(rootNode, childCount) # Perform Monte Carlo Tree Search
    # Print the index of the optimal node
    print("Optimal node: %d" % rootNode.childNodes.index(winnerNode) + 1)

