# Define the main function
def main():
    # Read input: number of test cases, number of lists, and the lists themselves
    import itertools
    n, m = map(int, input().split())
    li = [list(map(int, input().split()))[1:] for _ in range(m)]

    # Read input: pattern
    p = tuple(map(int, input().split()))

    # Create a set of all elements in the lists
    q = set(sum(li, []))

    # Create a set of numbers from 1 to n (excluding n)
    r = set(range(1, n+1))

    # Find the set of numbers in r that are not in q
    v = r - q

    # Initialize answer to 0
    ans = 0

    # Iterate through all possible subsets of q, from empty to the full set
    for i in range(0, len(q)+1):
        # Iterate through all combinations of i elements from q
        for s in itertools.combinations(q, i):
            # Iterate through each list and pattern
            for u, w in zip(li, p):
                # Convert s to a set
                s = set(s)
                # Check if the current combination of lists and pattern match the current subset of q
                if len(s & set(u)) % 2 != w:
                    # If not, break out of the inner loop and move on to the next combination
                    break
            # If all combinations of lists and pattern match the current subset of q, increment the answer
            else:
                ans += 2 ** len(v)

    # Print the answer
    print(ans)

# Run the main function if the script is executed directly
if __name__ == "__main__":
    main()
