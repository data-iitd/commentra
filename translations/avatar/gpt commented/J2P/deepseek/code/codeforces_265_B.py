import sys

def main():
    # Read the number of elements in the array from the console
    n = int(input().strip())
    
    # Read the array elements from the console
    arr = list(map(int, input().strip().split()))
    
    # Initialize the answer with the first element of the array plus one
    ans = arr[0] + 1
    
    # Calculate the total distance based on the differences between consecutive elements
    for i in range(1, n):
        # Add the absolute difference between the current and previous element, plus 2
        ans += abs(arr[i] - arr[i - 1]) + 2
    
    # Output the final calculated answer
    print(ans)

if __name__ == "__main__":
    main()
