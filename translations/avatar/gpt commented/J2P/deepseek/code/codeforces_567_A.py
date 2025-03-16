def main():
    # Reading the number of elements to be inputted
    a = int(input())
    
    # Initializing a list to hold the input integers
    ar = list(map(int, input().split()))
    
    # Loop to calculate and print the min and max differences for each element
    for i in range(a):
        # Calculating the maximum difference from the first and last elements
        max_diff = max(ar[i] - ar[0], ar[-1] - ar[i])
        
        # Calculating the minimum difference based on the position of the current element
        if i == 0:
            # If it's the first element, compare with the second element
            min_diff = ar[i + 1] - ar[i]
        elif i == a - 1:
            # If it's the last element, compare with the second last element
            min_diff = ar[i] - ar[i - 1]
        else:
            # For middle elements, compare with both neighbors
            min_diff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
        
        # Printing the minimum and maximum differences for the current element
        print(min_diff, max_diff)

if __name__ == "__main__":
    main()
