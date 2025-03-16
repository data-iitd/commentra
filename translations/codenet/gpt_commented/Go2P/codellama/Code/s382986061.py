
# Declare global variables for the number of elements (N), number of groups (K), 
# and temporary variables (d for group size, a for element).
N, K = 0, 0
d, a = 0, 0

def main():
    # Read the total number of elements (N) and the number of groups (K) from input.
    N, K = map(int, input().split())

    # Initialize a map to count occurrences of each element, with keys from 1 to N.
    as = {i: 0 for i in range(1, N+1)}

    # Process each group of elements.
    for i in range(K):
        # Read the size of the current group (d).
        d = int(input())
        # Read each element in the group and increment its count in the map.
        for j in range(d):
            a = int(input())
            as[a] += 1 # Increment the count for the element a.

    # Initialize a counter for elements that are not present in any group.
    ans = 0
    # Iterate through the counts of each element in the map.
    for _, v in as.items():
        # If an element's count is 0, it means it was not present in any group.
        if v == 0:
            ans += 1 # Increment the counter for missing elements.

    # Output the total count of elements that were not present in any group.
    print(ans)


