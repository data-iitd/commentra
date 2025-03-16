def main():
    # Read the number of players (n) and the number of levels (levels)
    n, levels = map(int, input().split())
    
    # Initialize variables to keep track of sums and counts
    sum_ = 0
    sum2 = 0
    sum3 = 0
    
    # Create a list to store the levels completed by the first player
    arr = list(map(int, input().split()))
    
    # Read the number of additional levels completed by the second player
    level2 = int(input())
    
    # Calculate the total number of levels completed by both players
    level3 = levels + level2
    
    # Create a list to store levels completed by both players
    arr2 = arr + list(map(int, input().split()))
    
    # Create a list to represent all levels (1 to n)
    arr3 = list(range(1, n + 1))
    
    # Check how many levels from arr3 are completed by either player
    count = 0
    for level in arr3:
        if level in arr2:
            count += 1
    
    # Determine if all levels have been completed by at least one player
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()
