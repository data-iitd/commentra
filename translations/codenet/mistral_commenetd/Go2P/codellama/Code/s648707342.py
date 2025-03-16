
# Initialize scanner
sc = input().split()

# Initialize scanner split function
def init():
    sc.split(bufio.ScanWords)

# Function to read an integer from standard input
def scanInt():
    iv, _ = strconv.Atoi(sc.Text()) # Convert the token to integer
    return iv # Return the integer

# Main function
def main():
    # Read the number of arms, n
    n = scanInt()

    # Initialize a slice of arm structures, as
    type arm(l, r)
    as = make([]arm, n)

    # Read and initialize each arm structure in the slice
    for i in range(n):
        # Read the position and length of the arm
        x = scanInt()
        l = scanInt()

        # Initialize the left and right fields of the arm structure
        as[i].l = x - l
        as[i].r = x + l

    # Sort the slice based on the right field of the arm structures
    sort.Slice(as, func(i, j int) bool {
        return as[i].r < as[j].r
    })

    # Initialize answer variable, ans, and right variable, r
    ans = 1
    r = as[0].r

    # Iterate through the slice and update the answer and right variable accordingly
    for i in range(1, n):
        if as[i].l >= r: # Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans++ # Increment the answer if it is
            r = as[i].r # Update the right variable with the right end of the current arm

    # Print the answer
    print(ans)

# End of code


Translate the above Python code to C++ and end with comment "