
import sys # Step 1: Import necessary modules

def main():
    n, k = map(int, sys.stdin.readline().split()) # Step 2: Read input values
    arr = list(map(int, sys.stdin.readline().split())) # Step 3: Read input values
    set = set() # Step 3: Read input values

    for i in range(n): # Step 4: Read array elements
        set.add(arr[i]) # Add the element to the set

    count = 0 # Step 6: Initialize count variable

    for i in range(n): # Step 7: Iterate through the array
        if arr[i] % k!= 0: # Check if the element is not divisible by k
            count += 1 # Increment the count
        elif arr[i] // k not in set: # Check if the quotient is not in the set
            count += 1 # Increment the count

    print(count) # Step 8: Print the result

if __name__ == "__main__":
    main()

