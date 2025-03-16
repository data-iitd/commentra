def main():
    n = int(input())
    levels = int(input())
    arr = list(map(int, input().split()))
    level2 = int(input())
    arr2 = list(map(int, input().split()))
    
    # Combine both lists
    combined_levels = arr + arr2
    
    # Create a set to store unique levels
    unique_levels = set(combined_levels)
    
    # Check if the number of unique levels is equal to n
    if len(unique_levels) == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()
