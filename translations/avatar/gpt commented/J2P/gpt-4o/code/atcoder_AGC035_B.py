class Main:
    def main():
        import sys
        from collections import defaultdict

        # Initialize input reading
        input = sys.stdin.read
        data = input().split()
        
        # Read the number of nodes and edges from input
        numNode = int(data[0])
        numEdge = int(data[1])
        
        # Create an adjacency list to represent the graph
        connect = defaultdict(list)
        
        # Read edges and populate the adjacency list
        index = 2
        for _ in range(numEdge):
            a = int(data[index]) - 1  # Read first node of the edge (0-indexed)
            b = int(data[index + 1]) - 1  # Read second node of the edge (0-indexed)
            connect[a].append(b)  # Add edge in both directions (undirected graph)
            connect[b].append(a)
            index += 2
        
        # Check if the number of edges is odd; if so, output -1 and exit
        if numEdge % 2 != 0:
            print(-1)
            return
        
        # Initialize arrays for tracking visited nodes and odd/even connections
        visited = [0] * numNode
        odd = [False] * numNode
        print_output = []  # List to accumulate output
        
        # Perform depth-first search starting from node 0
        dfs(0, -1, connect, visited, odd, print_output)
        
        # Output the result
        print(''.join(print_output))
    
    # Depth-first search method to explore the graph
    def dfs(crt, parent, connect, visited, odd, print_output):
        visited[crt] = 1  # Mark the current node as visited
        
        # Iterate through each child node connected to the current node
        for child in connect[crt]:
            # Skip the parent node and already visited nodes
            if child == parent or visited[child] == 1:
                continue
            elif visited[child] == 2:
                # If the child has been fully processed, append the edge to output
                print_output.append(f"{crt + 1} {child + 1}\n")
                odd[crt] = not odd[crt]  # Toggle the odd/even state
            else:
                # Recursively call DFS on the child node
                dfs(child, crt, connect, visited, odd, print_output)
                
                # Check the odd/even state of the child node after DFS
                if odd[child]:
                    print_output.append(f"{child + 1} {crt + 1}\n")
                    odd[child] = not odd[child]  # Toggle the state
                else:
                    print_output.append(f"{crt + 1} {child + 1}\n")
                    odd[crt] = not odd[crt]  # Toggle the state
        
        visited[crt] = 2  # Mark the current node as fully processed

# Call the main function
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
