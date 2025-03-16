def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the total number of levels
    levels = int(data[1])  # Read the number of levels the user has completed
    arr = list(map(int, data[2:2 + levels]))  # Read the levels completed by the user
    
    level2 = int(data[2 + levels])  # Read the number of levels the second user has completed
    arr2 = arr + list(map(int, data[3 + levels:3 + levels + level2]))  # Combine both users' completed levels
    
    arr3 = list(range(1, n + 1))  # Generate a sequence of numbers from 1 to n
    
    count = 0  # Initialize count to track the number of levels completed
    for i in arr3:
        if i in arr2:
            count += 1
    
    # Print the result based on whether all levels were completed
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
