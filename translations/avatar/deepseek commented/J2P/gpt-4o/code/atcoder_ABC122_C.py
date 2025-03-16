# Define a constant for modulo operations
mod = 1000000007

def main():
    # Create a Scanner object to read input
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Read the length of the string and the number of queries
    n, q = map(int, data[0].split())
    
    # Read the string
    c = data[1].strip()
    
    # Read the ranges for the queries and store them in a list
    range_queries = [list(map(int, line.split())) for line in data[2:2 + q]]
    
    # Initialize arrays to count "AC" fragments and store cumulative sums
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)
    
    # Process the string to find "AC" fragments
    for i in range(2, n + 1):
        if c[i - 2] == 'A' and c[i - 1] == 'C':
            # Increment the count of "AC" fragments at position i
            frag[i] += 1
        # Update the cumulative sum array
        rui[i] = rui[i - 1] + frag[i]
    
    # Process the queries
    results = []
    for left, right in range_queries:
        # Calculate the number of "AC" fragments in the given range
        results.append(rui[right] - rui[left])
    
    # Print all results
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
