
    # Inline function to read an integer from standard input
    def read():
        k = 0
        f = 1
        ch = input()
        # Initialize variables for reading an integer
        while ch < '0' or ch > '9':
            if ch == '-':
                f = -1
            ch = input()
        # Read digits and store them in 'k'
        while ch >= '0' and ch <= '9':
            k = k * 10 + int(ch) - int('0')
            ch = input()
        # Multiply the number by the sign and return it
        return k * f

    # Inline function to write an integer to standard output
    def write(x):
        if x < 0:
            x = -x
        # Write the digit in reverse order
        if x > 9:
            write(x // 10)
        print(x % 10 + '0', end='')

    # Inline function to write an integer and a newline to standard output
    def writeln(x):
        write(x)
        print()

    # Initialize variables
    n = read()
    m = read()
    l = 0
    r = 0
    vi = 0
    fa = [0] * (n + 1)
    v = [0] * (n + 1)

    # Inline function to get the root of a tree
    def get(x):
        if fa[x] == x:
            return x
        # Recursively find the root of the tree
        f = get(fa[x])
        # Update the depth of the nodes on the path from 'x' to the root
        v[x] += v[fa[x]]
        # Update the father of 'x'
        fa[x] = f
        return f

    # Main function
    def main():
        # Read the number of vertices 'n' and edges 'm'
        n = read()
        m = read()
        # Initialize the trees for each vertex
        for i in range(1, n + 1):
            fa[i] = i
        # Process each edge
        for i in range(1, m + 1):
            # Read the left and right endpoints and the value 'vi' of the edge
            l = read()
            r = read()
            vi = read()
            # Find the roots of the trees of the left and right endpoints
            li = get(l)
            ri = get(r)
            # If the roots are different, update the depth of the right tree and its father
            if li != ri:
                v[ri] += vi - v[r] + v[l]
                fa[ri] = li
            else:
                # If the roots are the same, check if the value of the edge is correct
                if v[r] - v[l] != vi:
                    print("No")
                    return
        # Output 'Yes' if all edges have the correct value
        print("Yes")

    # Call the main function
    main()

