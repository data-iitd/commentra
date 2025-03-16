def main():
    # Read the number of elements in round_complexity and george_complexity
    n, m = [int(i) for i in input().split()]
    
    # Read the complexities of the rounds
    round_complexity = [int(i) for i in input().split()]
    
    # Read the complexities of George's challenges
    george_complexity = [int(i) for i in input().split()]
    
    # Initialize counters for both lists
    i = j = 0
    
    # Loop through both lists to compare complexities
    while i < n and j < m:
        # Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        # Increment j to move to the next element in george_complexity
        j += 1
    
    # Print the number of rounds George can solve
    print(n - i)

# Check if the script is run as the main program
if __name__ == '__main__':
    main()
