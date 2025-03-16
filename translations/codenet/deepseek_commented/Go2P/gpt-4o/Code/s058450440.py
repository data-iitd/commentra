import sys
from collections import defaultdict

# Global variables
a = []  # a stores the counts of characters 'M', 'A', 'R', 'C', 'H'
ans = 0  # ans accumulates the result of the calculations performed by the dfs function

# dfs is a recursive function that calculates the product of 3 elements from list a
def dfs(left, i, res):
    global ans
    if left == 0:
        ans += res  # When no elements are left to multiply, add the result to ans
        return
    for j in range(i, len(a)):
        dfs(left - 1, j + 1, res * a[j])  # Recursively call dfs with updated parameters

# main function to execute the program
def main():
    n = int(sys.stdin.readline().strip())  # Read the number of characters
    dic = defaultdict(int)

    # Count occurrences of 'M', 'A', 'R', 'C', 'H'
    for _ in range(n):
        c = sys.stdin.readline().strip()[0]
        if c in 'MARCH':
            dic[c] += 1

    # Append the counts of 'M', 'A', 'R', 'C', 'H' to list a
    for v in dic.values():
        a.append(v)

    # Call dfs with parameters 3, 0, and 1
    dfs(3, 0, 1)
    print(ans)  # Print the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
