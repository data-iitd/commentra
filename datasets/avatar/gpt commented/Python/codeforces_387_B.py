def main():
    # Read the number of rounds (n) and the number of George's complexities (m)
    n, m = [int(i) for i in input().split()]
    
    # Read the complexities for each round into a list
    round_complexity = [int(i) for i in input().split()]
    
    # Read George's complexities into another list
    george_complexity = [int(i) for i in input().split()]
    
    # Initialize indices for both lists
    i = j = 0
    
    # Iterate through both lists to compare complexities
    while (i < n and j < m):
        # If the current round's complexity is less than or equal to George's complexity,
        # move to the next round
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        # Always move to the next complexity of George
        j += 1
    
    # Output the number of rounds that George cannot handle
    print(n - i)

# Entry point of the program
if __name__ == '__main__':
    main()
