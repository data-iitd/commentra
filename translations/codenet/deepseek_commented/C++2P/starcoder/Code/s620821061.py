
# Python3 program to solve the problem

# Class to represent a graph
class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = []

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph.append([u, v])

    # A DFS based recursive function that returns true if a matching
    # for vertex u is possible
    def bpm(self, u, matchR, seen):

        # Try every edge adjacent to u
        for v in self.graph[u]:
            if seen[v] == False:

                # If the edge is matched to v, return true
                if matchR[v] == -1 or self.bpm(matchR[v], matchR, seen):
                    matchR[v] = u
                    return True
        return False

    # Returns maximum number of matching
    def maxBPM(self):
        matchR = [-1] * self.V
        result = 0  # Count of matching

        # Keep looping until a complete matching is
        # possible
        while True:

            # Consider all vertices as not seen for next
            # iteration
            seen = [False] * (self.V)

            # Find if the current matching is complete
            # by trying every edge one by one
            for i in range(self.V):
                if seen[i] == False:

                    # Returns true if a matching for vertex i
                    # is possible
                    if self.bpm(i, matchR, seen) == False:
                        break

            # If a complete matching for vertex i is not
            # possible, then remove it from the matching
            else:
                result += 1
                continue

            # If we reach here, a complete matching is not
            # possible
            break
        return result


# Driver Code
if __name__ == "__main__":
    t = int(input())
    while t:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        g = Graph(n)
        for i in range(m):
            u, v = map(int, input().split())
            g.addEdge(u, v)
        print(g.maxBPM())
        t -= 1

