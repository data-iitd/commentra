# Constants for large prime numbers used in modular arithmetic.
INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

# Constants for black cell representation.
Black = 35

# Function to count the number of black cells in a grid.
def count_black(h, w, m):
    count = 0
    for i in range(h):
        for j in range(w):
            if m[i][j] == Black:
                count += 1
    return count

# Function to solve the problem.
def solve(h, w, a, m):
    result = 0
    for i in range(1 << h):
        for k in range(1 << w):
            tmp = [row[:] for row in m]  # Create a copy of the grid
            for j in range(h):
                if (1 << j) & i:
                    for l in range(w):
                        tmp[j][l] = 1
            for j in range(w):
                if (1 << j) & k:
                    for l in range(h):
                        tmp[l][j] = 1
            if count_black(h, w, tmp) == a:
                result += 1
    return result

# Main function for solving the problem.
def main():
    # Read input
    h, w, a = map(int, input().split())
    m = [list(map(int, input().strip())) for _ in range(h)]

    # Solve the problem
    answer = solve(h, w, a, m)

    # Print the result
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
