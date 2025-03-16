def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    len_a = int(data[0])  # Read the length of the array
    a = list(map(int, data[1:len_a + 1]))  # Initialize the array with the length read
    
    l = 0  # Initialize the starting index of the misplaced element
    r = 0  # Initialize the ending index of the misplaced element
    flag = False  # Flag to indicate the start of the misplaced segment
    isTrue = False  # Flag to indicate if the segment is unsorted
    
    for i in range(len_a):
        if a[i] != i + 1 and not flag:  # Check for the first misplaced element
            l = i + 1  # Set the starting index
            flag = True  # Set the flag to true
            continue  # Continue to the next iteration
        
        if a[i] != i + 1 and flag:  # Check for the second misplaced element
            r = i + 1  # Set the ending index
            if (a[r - 1] - a[r - 2] > 0):  # Check if the segment is unsorted
                isTrue = True  # Set the flag to true
                break  # Break out of the loop
    
    print(f"{l} {r}" if not isTrue else "0 0")  # Print the indices or "0 0" if no such segment exists

if __name__ == "__main__":
    main()

# <END-OF-CODE>
