import sys
from collections import defaultdict

# Global variables to store counts and the result
a = []  # List to hold counts of specific characters
ans = 0  # Variable to hold the final answer

# Depth-first search function to calculate combinations
def dfs(left, i, res):
    global ans
    # If no more characters left to choose, add the result to ans
    if left == 0:
        ans += res
        return
    # Iterate through the list starting from index i
    for j in range(i, len(a)):
        # Recursive call to dfs with one less character to choose
        dfs(left - 1, j + 1, res * a[j])

def main():
    global a, ans
    # Read the number of characters
    n = int(sys.stdin.readline().strip())
    # Dictionary to count occurrences of specific characters
    dic = defaultdict(int)

    # Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for _ in range(n):
        c = sys.stdin.readline().strip()[0]  # Read the first character of the string
        if c in 'MARCH':
            dic[c] += 1  # Increment count for the character if it's one of the specified

    # Populate the list a with the counts from the dictionary
    for v in dic.values():
        a.append(v)

    # Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1)
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
