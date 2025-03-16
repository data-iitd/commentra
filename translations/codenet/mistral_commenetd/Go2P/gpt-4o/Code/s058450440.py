import sys
from collections import defaultdict
from itertools import combinations

# Function to perform Depth First Search (DFS) algorithm
def dfs(left, i, res):
    global ans
    if left == 0:
        ans += res
        return

    for j in range(i, len(a)):
        dfs(left - 1, j + 1, res * a[j])

# Main function definition
def main():
    global a, ans
    a = []
    ans = 0

    # Reading the number of test cases
    n = int(sys.stdin.readline().strip())

    # Initializing an empty dictionary to store the frequency of each character
    dic = defaultdict(int)

    # Reading strings and updating the dictionary
    for _ in range(n):
        c = sys.stdin.readline().strip()[0]
        if c in 'MARCH':
            dic[c] += 1

    # Converting dictionary values to integers and appending them to the 'a' list
    for v in dic.values():
        a.append(v)

    # Calling the 'dfs' function with initial arguments
    dfs(3, 0, 1)

    # Printing the answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
