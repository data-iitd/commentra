
import random
import math
import sys

WIN_SCORE = 10
TIME_LIMIT = 500

class Node:
    def __init__(self, parent, isPlayersTurn):
        self.parent = parent
        self.childNodes = []
        self.isPlayersTurn = isPlayersTurn
        self.playerWon = False
        self.score = 0
        self.visitCount = 0

def monteCarloTreeSearch(rootNode, childCount):
    winnerNode = None
    timeLimit = time.time() + TIME_LIMIT
    while time.time() < timeLimit:
        promisingNode = getPromisingNode(rootNode)
        if promisingNode.childNodes == []:
            addChildNodes(promisingNode, childCount)
        simulateRandomPlay(promisingNode)
    winnerNode = getWinnerNode(rootNode)
    printScores(rootNode)
    return winnerNode

def addChildNodes(node, childCount):
    for i in range(childCount):
        node.childNodes.append(Node(node, not node.isPlayersTurn))

def getPromisingNode(rootNode):
    promisingNode = rootNode
    while promisingNode.childNodes!= []:
        uctIndex = float("-inf")
        nodeIndex = 0
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

def simulateRandomPlay(promisingNode):
    rand = random.Random()
    tempNode = promisingNode
    isPlayerWinner = rand.choice([True, False])
    while tempNode!= None:
        tempNode.visitCount += 1
        if (tempNode.isPlayersTurn and isPlayerWinner) or (not tempNode.isPlayersTurn and not isPlayerWinner):
            tempNode.score += WIN_SCORE
        tempNode = tempNode.parent

def getWinnerNode(rootNode):
    return max(rootNode.childNodes, key=lambda c: c.score)

def printScores(rootNode):
    print("Node\tScore\tVisits")
    for i in range(len(rootNode.childNodes)):
        print(i + 1, rootNode.childNodes[i].score, rootNode.childNodes[i].visitCount)

if __name__ == "__main__":
    childCount = int(sys.stdin.readline())
    isPlayersTurn = sys.stdin.readline().strip() == "True"
    rootNode = Node(None, isPlayersTurn)
    winnerNode = monteCarloTreeSearch(rootNode, childCount)
    print("Optimal node: " + str(rootNode.childNodes.index(winnerNode) + 1))

