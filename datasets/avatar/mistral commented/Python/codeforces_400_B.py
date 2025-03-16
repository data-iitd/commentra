# Read input
n, m = map(int, input().split())

# Initialize an empty set
c = set()

# Populate set c with differences between indices of 'S' and 'G' in each string
for s in input().split():
    # Find the indices of 'S' and 'G' in the current string
    index_S = s.find('S')
    index_G = s.find('G')

    # Calculate the difference and add it to the set
    difference = index_S - index_G
    c.add(difference)

# Check if there is any negative number in set c and print accordingly
print(-1 if any(a < 0 for a in c) else len(c))