class Main:
    # Declare arrays to hold input values and variables for dimensions and result
    a = None
    b = None
    c = None
    d = None
    n = 0
    m = 0
    q = 0
    ans = -100  # Initialize answer to a very low value

    @staticmethod
    def main():
        # Create a Scanner object for input
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the values of n, m, and q from input
        Main.n = int(data[0])
        Main.m = int(data[1])
        Main.q = int(data[2])
        
        # Initialize arrays based on the number of queries (q)
        Main.a = [0] * Main.q
        Main.b = [0] * Main.q
        Main.c = [0] * Main.q
        Main.d = [0] * Main.q
        
        # Read the query parameters into the arrays
        index = 3
        for i in range(Main.q):
            Main.a[i] = int(data[index]) - 1  # Store a[i] (0-indexed)
            Main.b[i] = int(data[index + 1]) - 1  # Store b[i] (0-indexed)
            Main.c[i] = int(data[index + 2])  # Store c[i]
            Main.d[i] = int(data[index + 3])  # Store d[i]
            index += 4
        
        # Start the depth-first search (DFS) to find the maximum score
        Main.dfs([])

        # Output the maximum score found
        print(Main.ans)

    @staticmethod
    def dfs(lst):
        # Check if the current list has reached the required size (n)
        if len(lst) == Main.n:
            score = 0  # Initialize score for the current configuration
            
            # Calculate the score based on the queries
            for i in range(Main.q):
                # If the condition is met, add the corresponding value to the score
                score += (lst[Main.b[i]] - lst[Main.a[i]] == Main.c[i]) * Main.d[i]
            
            # Update the maximum score if the current score is higher
            Main.ans = max(Main.ans, score)
            return
        
        # If the list is not empty, continue adding numbers from the last added number to m
        if lst:
            for num in range(lst[-1], Main.m + 1):
                lst.append(num)  # Add the current number to the list
                Main.dfs(lst)    # Recur with the updated list
                lst.pop()        # Backtrack by removing the last number
        else:
            # If the list is empty, start adding numbers from 1 to m
            for num in range(1, Main.m + 1):
                lst.append(num)  # Add the current number to the list
                Main.dfs(lst)    # Recur with the updated list
                lst.pop()        # Backtrack by removing the last number

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
