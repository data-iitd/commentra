def main():
    # Read the number of elements and the modulo value
    n, m = map(int, input().split())
    
    # Read the array of elements
    a = list(map(int, input().split()))
    
    # Initialize the answer and base variable
    ans = 0
    base = 0
    
    # HashMap to store the frequency of remainders
    dp = {}
    
    # Iterate through the array to calculate the answer
    for i in range(n):
        # Update the base variable
        base = (base - a[i] % m + m) % m
        
        # Update the frequency of remainders in the dictionary
        dp[(base + a[i]) % m] = dp.get((base + a[i]) % m, 0) + 1
        
        # Add the frequency of the current remainder to the answer
        ans += dp.get(base, 0)
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()
