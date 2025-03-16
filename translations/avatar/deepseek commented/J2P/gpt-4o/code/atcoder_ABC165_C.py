class Main:
    # Arrays to store input values
    a = None
    b = None
    c = None
    d = None
    
    # Variables to store input values
    n = 0
    m = 0
    q = 0
    
    # Variable to store the maximum score
    ans = -100

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read values of n, m, and q
        Main.n = int(data[0])
        Main.m = int(data[1])
        Main.q = int(data[2])
        
        # Initialize arrays to store the conditions
        Main.a = [0] * Main.q
        Main.b = [0] * Main.q
        Main.c = [0] * Main.q
        Main.d = [0] * Main.q
        
        # Read the conditions into the arrays
        index = 3
        for i in range(Main.q):
            Main.a[i] = int(data[index]) - 1  # Adjusting for 0-based index
            Main.b[i] = int(data[index + 1]) - 1  # Adjusting for 0-based index
            Main.c[i] = int(data[index + 2])
            Main.d[i] = int(data[index + 3])
            index += 4
        
        # Start the DFS with an empty list
        Main.dfs([])

        # Print the maximum score found
        print(Main.ans)

    @staticmethod
    def dfs(lst):
        # If the list size equals n, calculate the score and update ans
        if len(lst) == Main.n:
            score = 0
            for i in range(Main.q):
                if lst[Main.b[i]] - lst[Main.a[i]] == Main.c[i]:
                    score += Main.d[i]
            Main.ans = max(Main.ans, score)
            return
        
        # If the list is not empty, continue adding numbers from the last number in the list
        if lst:
            for num in range(lst[-1], Main.m + 1):
                lst.append(num)
                Main.dfs(lst)
                lst.pop()
        else:
            # If the list is empty, start with numbers from 1 to m
            for num in range(1, Main.m + 1):
                lst.append(num)
                Main.dfs(lst)
                lst.pop()

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
