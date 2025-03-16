def main():
    # Step 1: Read the length of the array
    len_array = int(input())
    
    # Step 2: Read the elements of the array
    a = list(map(int, input().split()))
    
    # Step 3: Perform Insertion Sort
    for j in range(1, len_array):
        # Print the array before each iteration
        print(" ".join(map(str, a)))
        
        # Store the current element to be inserted
        key = a[j]
        
        # Shift elements to the right to make space for the key
        i = j - 1
        while i >= 0 and a[i] > key:
            a[i + 1] = a[i]
            i -= 1
        
        # Insert the key into the correct position
        a[i + 1] = key
    
    # Step 4: Print the sorted array
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
