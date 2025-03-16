
import sys # Importing utility module for input handling

def main():
    n = int(input()) # Read the number of elements
    ans = list(map(int, input().split())) # Read the array elements and convert to list
    
    # Sort the list in ascending order
    ans.sort()
    
    # Initialize count with the largest element in the list
    count = ans[-1]
    
    # Iterate through the list from the second-to-last element to the first
    for i in range(n - 2, -1, -1):
        if ans[i] < ans[i + 1]:
            count += ans[i] # Add the current element to count if it's less than the next element
        else:
            while ans[i] >= ans[i + 1]:
                ans[i] -= 1 # Decrease the current element until it's less than the next element
            if ans[i] > 0:
                count += ans[i] # Add the adjusted current element to count
    
    # Print the final count
    print(count)

if __name__ == "__main__":
    main()

