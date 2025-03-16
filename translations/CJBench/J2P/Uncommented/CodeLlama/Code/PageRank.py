
import sys

def main():
    nodes = int(sys.stdin.readline())
    path = [[0 for i in range(nodes+1)] for j in range(nodes+1)]
    pagerank = [0 for i in range(nodes+1)]
    for i in range(1, nodes+1):
        for j in range(1, nodes+1):
            path[i][j] = int(sys.stdin.readline())
            if i == j:
                path[i][j] = 0
    calc(nodes, path, pagerank)

def calc(totalNodes, path, pagerank):
    initialMain = 1.0 / totalNodes
    dampingFactor = 0.85
    tempMain = [0 for i in range(totalNodes+1)]
    for i in range(1, totalNodes+1):
        pagerank[i] = initialMain
    iterationStep = 1
    while iterationStep <= 2:
        for i in range(1, totalNodes+1):
            tempMain[i] = pagerank[i]
            pagerank[i] = 0
        for internalNode in range(1, totalNodes+1):
            for externalNode in range(1, totalNodes+1):
                if path[externalNode][internalNode] == 1:
                    outgoingLinks = 0
                    for k in range(1, totalNodes+1):
                        if path[externalNode][k] == 1:
                            outgoingLinks += 1
                    pagerank[internalNode] += tempMain[externalNode] / outgoingLinks
        for i in range(1, totalNodes+1):
            pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i]
        iterationStep += 1
    for i in range(1, totalNodes+1):
        print("Page Rank of Node %d: %.6f" % (i, pagerank[i]))

if __name__ == "__main__":
    main()

