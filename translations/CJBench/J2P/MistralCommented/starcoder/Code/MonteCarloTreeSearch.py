
import random
import sys

# Define a custom Node class for the tree
class Node:
    def __init__(self, parent, isPlayersTurn):
        self.parent = parent
        self.childNodes = []
        self.isPlayersTurn = isPlayersTurn
        self.playerWon = False
        self.score = 0
        self.visitCount = 0

    # Define a comparator for the nodes
    def __lt__(self, other):
        return self.score < other.score

# Constants for the game
WIN_SCORE = 10
TIME_LIMIT = 500

# Main method for Monte Carlo Tree Search
def monteCarloTreeSearch(rootNode, childCount):
    winnerNode = None
    timeLimit = time.time() + TIME_LIMIT

    # Add child nodes to the root node
    addChildNodes(rootNode, childCount)

    # Search for the promising node within the time limit
    while time.time() < timeLimit:
        promisingNode = getPromisingNode(rootNode)

        # If there are no child nodes for the promising node, add them
        if len(promisingNode.childNodes) == 0:
            addChildNodes(promisingNode, childCount)

        # Simulate random play for the promising node
        simulateRandomPlay(promisingNode)

    # Find the winning node
    winnerNode = getWinnerNode(rootNode)

    # Print the scores for all nodes in the tree
    printScores(rootNode)

    return winnerNode

# Add child nodes to the given node
def addChildNodes(node, childCount):
    for i in range(childCount):
        node.childNodes.append(Node(node, not node.isPlayersTurn))

# Find the promising node based on UCT (Upper Confidence Bound)
def getPromisingNode(rootNode):
    promisingNode = rootNode

    # Traverse the tree to find the promising node
    while len(promisingNode.childNodes) > 0:
        maxUct = -sys.maxsize
        bestChildNode = None

        # Find the child node with the highest UCT value
        for childNode in promisingNode.childNodes:
            uctValue = (childNode.visitCount == 0) \
               ? sys.maxsize \
                : ((childNode.score / childNode.visitCount) \
                    + 1.41 * math.sqrt(math.log(promisingNode.visitCount) / childNode.visitCount))

            # Update the best child node if the UCT value is higher
            if uctValue > maxUct:
                maxUct = uctValue
                bestChildNode = childNode

        # Update the promising node to the best child node
        promisingNode = bestChildNode

    return promisingNode

# Simulate random play for the given node
def simulateRandomPlay(promisingNode):
    rand = random.Random()
    currentNode = promisingNode

    # Simulate the game by following the tree until reaching the root node
    while currentNode!= None:
        currentNode.visitCount += 1

        # Update the score if the player wins or loses
        if (currentNode.isPlayersTurn and rand.nextBoolean()) or (not currentNode.isPlayersTurn and not rand.nextBoolean()):
            currentNode.score += WIN_SCORE

        currentNode = currentNode.parent

# Find the winning node with the highest score
def getWinnerNode(rootNode):
    return max(rootNode.childNodes, key=lambda c: c.score)

# Print the scores and visits for all nodes in the tree
def printScores(rootNode):
    print("Node\tScore\tVisits")

    # Traverse the tree and print the scores and visits for each node
    for node in rootNode.childNodes:
        print(f"{node.index + 1}\t{node.score}\t{node.visitCount}")

# Main method for running the Monte Carlo Tree Search algorithm
if __name__ == "__main__":
    childCount = int(input())
    isPlayersTurn = input().lower() == "true"

    mcts = Main()
    rootNode = mcts.new Node(None, isPlayersTurn)

    # Perform Monte Carlo Tree Search and find the winning node
    winnerNode = monteCarloTreeSearch(rootNode, childCount)

    # Print the index of the winning node
    print(f"Optimal node: {rootNode.childNodes.index(winnerNode) + 1}")

