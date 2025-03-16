import sys

# Initializing the size of the arrays
N = 200 + 10
# Initializing the failure function array
f = [0] * N
# Initializing the character arrays
b = [0] * N

def getFail(b, m):
    # Function declaration and initialization of variables
    j = 0
    f[0] = f[1] = 0

    # Main logic of the function
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

def main():
    # Main function declaration and initialization of variables
    inp = sys.stdin.readline
    # Reading the number of characters in the strings
    n = int(inp().strip())
    # Reading the two strings from the input
    s1 = inp().strip()
    s2 = inp().strip()

    cnt = 0

    # Concatenating the two strings and creating character arrays for each
    for i in range(n):
        b[cnt + 1] = s2[i]
        cnt += 1
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1

    getFail(b, cnt)

    # Computing the length of the longest common prefix
    len_ = min(f[cnt], min(n, n))

    # Writing the output to the console
    print(2 * n - len_)

# Call the main function
if __name__ == "__main__":
    main()
