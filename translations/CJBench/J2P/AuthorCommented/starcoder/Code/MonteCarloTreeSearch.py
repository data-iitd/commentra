
import random
import math

# Monte Carlo Tree Search (MCTS) is a heuristic search algorithm used in
# decition taking problems especially games.
#
# See more: https://en.wikipedia.org/wiki/Monte_Carlo_tree_search,
# https://www.baeldung.com/java-monte-carlo-tree-search

# WIN_SCORE is the score a player gets for winning a game.
WIN_SCORE = 10

# TIME_LIMIT is the time the algorithm will be running for (in milliseconds).
TIME_LIMIT = 500

# Node class
class Node:
    def __init__(self, parent, isPlayersTurn):
        self.parent = parent
        self.childNodes = []
        self.isPlayersTurn = isPlayersTurn
        self.playerWon = False
        self.score = 0
        self.visitCount = 0

# monteCarloTreeSearch()
#
# Explores a game tree using Monte Carlo Tree Search (MCTS) and returns the
# most promising node.
#
# @param rootNode Root node of the game tree.
# @return The most promising child of the root node.
def monteCarloTreeSearch(rootNode, childCount):
    winnerNode = None
    timeLimit = time.time() + TIME_LIMIT

    # Expand the root node with a given number of children.
    addChildNodes(rootNode, childCount)

    # Explore the tree until the time limit is reached.
    while time.time() < timeLimit:
        promisingNode = getPromisingNode(rootNode)

        # Expand the promising node.
        if len(promisingNode.childNodes) == 0:
            addChildNodes(promisingNode, childCount)

        simulateRandomPlay(promisingNode)

    winnerNode = getWinnerNode(rootNode)
    printScores(rootNode)

    return winnerNode

# addChildNodes()
#
# Adds a given number of child nodes to a given node.
#
# @param node Node to add child nodes to.
# @param childCount Number of child nodes to add.
def addChildNodes(node, childCount):
    for i in range(childCount):
        node.childNodes.append(Node(node, not node.isPlayersTurn))

# getPromisingNode()
#
# Uses UCT to find a promising child node to be explored.
#
# UCT: Upper Confidence bounds applied to Trees.
#
# @param rootNode Root node of the tree.
# @return The most promising node according to UCT.
def getPromisingNode(rootNode):
    promisingNode = rootNode

    # Iterate until a node that hasn't been expanded is found.
    while len(promisingNode.childNodes) > 0:
        uctIndex = float("-inf")
        nodeIndex = 0

        # Iterate through child nodes and pick the most promising one
        # using UCT (Upper Confidence bounds applied to Trees).
        for i in range(len(promisingNode.childNodes)):
            childNode = promisingNode.childNodes[i]
            uctTemp = (childNode.visitCount == 0) \
               ? float("inf") \
                : ((childNode.score / childNode.visitCount) \
                    + 1.41 * math.sqrt(math.log(promisingNode.visitCount) / childNode.visitCount))

            if uctTemp > uctIndex:
                uctIndex = uctTemp
                nodeIndex = i

        promisingNode = promisingNode.childNodes[nodeIndex]

    return promisingNode

# simulateRandomPlay()
#
# Simulates a random play from a nodes current state and back propagates
# the result.
#
# @param promisingNode Node that will be simulated.
def simulateRandomPlay(promisingNode):
    rand = random.Random()
    tempNode = promisingNode
    isPlayerWinner = rand.nextBoolean() # Random outcome for demonstration.

    while tempNode!= None:
        tempNode.visitCount += 1

        if ((tempNode.isPlayersTurn and isPlayerWinner) or (not tempNode.isPlayersTurn and not isPlayerWinner)):
            tempNode.score += WIN_SCORE

        tempNode = tempNode.parent

# getWinnerNode()
#
# Returns the node with the highest score.
#
# @param rootNode Root node of the tree.
# @return The node with the highest score.
def getWinnerNode(rootNode):
    return max(rootNode.childNodes, key = lambda c: c.score)

# printScores()
#
# Prints the scores of all nodes in a tree.
#
# @param rootNode Root node of the tree.
def printScores(rootNode):
    print("Node\tScore\tVisits")
    for i in range(len(rootNode.childNodes)):
        print("%d\t%d\t%d" % (i + 1, rootNode.childNodes[i].score, rootNode.childNodes[i].visitCount))

# main()
#
# Main function.
def main():
    # Input: Number of children for the root node
    childCount = int(input())

    # Input: Is it the player's turn at the root node
    isPlayersTurn = input() == "True"

    # Run Monte Carlo Tree Search
    mcts = Main()
    rootNode = mcts.new Node(None, isPlayersTurn)
    winnerNode = mcts.monteCarloTreeSearch(rootNode, childCount)

    # Output: Optimal node index
    print("Optimal node: %d" % rootNode.childNodes.index(winnerNode) + 1)

if __name__ == "__main__":
    main()

