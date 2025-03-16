

# Initialize scanner
sc = bufio.Scanner(sys.stdin)

# Initialize scanner split function
sc.whitespace = re.compile(r'\n')

# Function to read an integer from standard input
def scanInt():
    sc.scan() # Scan the next token
    iv = int(sc.token()) # Convert the token to integer
    return iv # Return the integer

# Main function
def main():
    # Read the number of arms, n
    n = scanInt()

    # Initialize a list of arm structures, as
    class arm:
        def __init__(self, l, r):
            self.l = l
            self.r = r
    as = [arm(0, 0) for _ in range(n)]

    # Read and initialize each arm structure in the list
    for i in range(n):
        # Read the position and length of the arm
        x = scanInt()
        l = scanInt()

        # Initialize the left and right fields of the arm structure
        as[i].l = x - l
        as[i].r = x + l

    # Sort the list based on the right field of the arm structures
    as.sort(key=lambda arm: arm.r)

    # Initialize answer variable, ans, and right variable, r
    ans = 1
    r = as[0].r

    # Iterate through the list and update the answer and right variable accordingly
    for i in range(1, n):
        if as[i].l >= r: # Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans += 1 # Increment the answer if it is
            r = as[i].r # Update the right variable with the right end of the current arm

    # Print the answer
    print(ans)

    # End of code

