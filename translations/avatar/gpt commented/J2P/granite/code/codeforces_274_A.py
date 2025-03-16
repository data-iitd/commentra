
import sys

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Read the value of k
    k = int(input())
    
    # Initialize an array to hold the input numbers
    arr = list(map(int, input().split()))
    
    # Create a set to store unique elements that meet the criteria
    s = set()
    
    # Read n integers into the array
    for i in range(n):
        arr[i] = int(arr[i])
    
    # Initialize a counter to keep track of valid elements
    count = 0
    
    # Iterate through the array to apply the conditions
    for i in range(n):
        # Check if the current element is not divisible by k
        if arr[i] % k!= 0:
            count += 1 # Increment count for valid element
            s.add(arr[i]) # Add the element to the set
        # Check if the current element is divisible by k and its corresponding k-factor is not in the set
        elif arr[i] // k not in s:
            count += 1 # Increment count for valid element
            s.add(arr[i]) # Add the element to the set
    
    # Output the final count of valid elements
    print(count)

if __name__ == "__main__":
    main()

