
# Python code

# Function to read input
def read():
    return int(input())

# Function to write output
def write(x):
    print(x, end=" ")

# Function to write output on new line
def writeln(x):
    print(x)

# Main function
if __name__ == "__main__":
    # Reading input
    n = read()

    # Reading array 'a'
    a = [read() for _ in range(n)]

    # Sorting array 'a' in ascending order
    a.sort()

    # Finding duplicate elements and storing them in 'q'
    q = []
    for i in range(n):
        if i < n-1 and a[i] == a[i+1]:
            q.append(a[i])
            i += 1

    # Outputting the result
    writeln(q[-1] * q[-2])

# End of Python code
