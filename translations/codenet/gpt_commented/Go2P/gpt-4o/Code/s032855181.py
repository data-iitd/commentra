def group(n):
    # group function determines the group classification based on the input number n.
    # It returns "B" for specific values (4, 6, 9, 11) and "A" for all other values.
    if n in {4, 6, 9, 11}:
        return "B"
    else:
        return "A"

def main():
    # Read two integers from standard input
    x, y = map(int, input().split())

    # Check if either x or y is equal to 2, and print "No" if true
    if x == 2 or y == 2:
        print("No")
        return  # Exit the function early if the condition is met

    # Determine the group classification for both x and y
    xg = group(x)
    yg = group(y)

    # Compare the group classifications of x and y
    # Print "Yes" if they belong to the same group, otherwise print "No"
    if xg == yg:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
