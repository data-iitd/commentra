def main():
    import sys
    
    # Read values into the 3x3 array `c`
    c = []
    for _ in range(3):
        row = list(map(int, sys.stdin.readline().strip().split()))
        c.append(row)

    # Initialize a and b arrays
    a = [0] * 3
    b = [0] * 3

    # Calculate the values of `b` based on the initial assumption that `a[0]` is zero
    b[0] = c[0][0] - a[0]
    b[1] = c[0][1] - a[0]
    b[2] = c[0][2] - a[0]

    # Calculate the values of `a` based on the values in `c`
    a[1] = c[1][0] - c[0][0]
    a[2] = c[2][0] - c[0][0]

    # Check if the calculated values of `a` and `c` are consistent with the given relationships
    if (a[1] == c[1][1] - c[0][1] and 
        a[1] == c[1][2] - c[0][2] and 
        a[2] == c[2][1] - c[0][1] and 
        a[2] == c[2][2] - c[0][2]):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
# <END-OF-CODE>
