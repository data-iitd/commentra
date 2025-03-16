def main():
    # Importing the itertools module for combinatorial functions
    import itertools
    
    # Reading the values of n and m from input
    n, m = map(int, input().split())
    
    # Reading m lists of integers, each containing values after the first element
    li = [list(map(int, input().split()))[1:] for _ in range(m)]
    
    # Reading a tuple p from input
    p = tuple(map(int, input().split()))
    
    # Creating a set q that contains all unique elements from the lists in li
    q = set(sum(li, []))
    
    # Creating a set r that contains all integers from 1 to n
    r = set(range(1, n + 1))
    
    # Finding the set of values v that are in r but not in q
    v = r - q
    
    # Initializing the answer variable to count valid combinations
    ans = 0
    
    # Iterating over all possible sizes of combinations from the set q
    for i in range(0, len(q) + 1):
        # Generating combinations of size i from the set q
        for s in itertools.combinations(q, i):
            # Checking each list in li against the corresponding value in p
            for u, w in zip(li, p):
                s = set(s)  # Converting the combination to a set for intersection
                # If the count of common elements is odd and does not match w, break
                if len(s & set(u)) % 2 != w:
                    break
            else:
                # If all checks passed, increment the answer by 2 raised to the power of the size of v
                ans += 2 ** (len(v))
    
    # Printing the final answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()
