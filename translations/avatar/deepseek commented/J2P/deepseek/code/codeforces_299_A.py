def main():
    # Step 1: Read the input value n, which represents the number of elements in the array.
    n = int(input())
    a = list(map(int, input().split()))
    
    # Step 2: Sort the array 'a'.
    a.sort()
    
    # Step 3: Find the minimum element in the sorted array 'a'.
    min_val = a[0]
    
    # Step 4: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
    for value in a:
        if value % min_val != 0:
            print(-1)
            return
    
    # Step 5: If all elements are divisible, print the minimum element.
    print(min_val)

# Call the main function
main()

