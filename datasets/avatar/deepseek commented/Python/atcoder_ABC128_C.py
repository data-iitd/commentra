def main():
    import itertools
    # Read the number of switches (n) and the number of bulbs (m)
    n, m = map(int, input().split())
    
    # Read the connections of switches for each bulb and store them in a list (li)
    # Each element in li is a list of switches connected to a bulb, excluding the bulb itself
    li = [list(map(int, input().split()))[1:] for _ in range(m)]
    
    # Read the pattern of on/off states for each bulb and store it in a tuple (p)
    p = tuple(map(int, input().split()))
    
    # Create a set (q) containing all the switches from all the bulbs
    q = set(sum(li, []))
    
    # Create a set (r) containing all the switches from 1 to n
    r = set(range(1, n + 1))
    
    # Calculate the set (v) which contains the switches that are not connected to any bulb
    v = r - q
    
    # Initialize the answer variable to count the number of valid configurations
    ans = 0
    
    # Iterate over all possible combinations of switches from q
    for i in range(0, len(q) + 1):
        for s in itertools.combinations(q, i):
            # Check if each combination satisfies the given pattern p
            for u, w in zip(li, p):
                s = set(s)
                if len(s & set(u)) % 2 != w:
                    break
            else:
                # If a combination satisfies the pattern, increment the answer by 2^len(v)
                ans += 2 ** len(v)
    
    # Print the total number of valid configurations
    print(ans)

if __name__ == "__main__":
    main()
