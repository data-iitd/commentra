def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Reading the size of the matrix
    arr = [[None] * n for _ in range(n)]  # Initializing the 2D character array
    str_list = data[1:n + 1]  # Reading n strings

    # Populating the 2D character array from the strings
    for i in range(n):
        for j in range(n):
            arr[i][j] = str_list[i][j]

    # Comparing the first two characters to determine a and b
    a = arr[0][0]
    b = arr[0][1]

    # If the characters are the same, print "NO" and exit
    if a == b:
        print("NO")
    else:
        res = True  # Initialize result as true

        # Iterating through the matrix to validate the pattern
        for i in range(n):
            for j in range(n):
                if i == j or i + j == n - 1:  # Check diagonal elements
                    if arr[i][j] != a:  # If diagonal element is not a, set res to false
                        res = False
                        break
                else:  # Check off-diagonal elements
                    if arr[i][j] != b:  # If off-diagonal element is not b, set res to false
                        res = False
                        break

        # Printing the result
        if res:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
