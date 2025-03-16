# Import the necessary module
import sys

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize a flag to indicate if a valid triplet is found
    f = 0
    
    # Create a list to store the input integers
    a = list(map(int, input().split()))
    
    # Iterate through each element in the array
    for k in range(n):
        # Store the current element to check against pairs
        t = a[k]
        
        # Check for pairs in the array that sum up to the current element
        for i in range(n):
            for j in range(n):
                # Ensure we are not using the same element twice
                if i != j and t == (a[i] + a[j]):
                    # Set the flag to indicate a valid triplet is found
                    f = 1
                    break
            # Break out of the loop if a valid pair is found
            if f == 1:
                break
        # Break out of the outer loop if a valid triplet is found
        if f == 1:
            break
    
    # Output the result: indices of the triplet or -1 if not found
    if f == 1:
        print(f"{k + 1} {j + 1} {i + 1}")
    else:
        print("-1")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
