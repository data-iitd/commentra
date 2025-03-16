def main():
    # Read the number of elements from the user
    n = int(input())
    
    # Initialize a list to hold the Long integers
    ans = []
    
    # Read n Long integers from the user and store them in the list
    for _ in range(n):
        ans.append(int(input()))
    
    # Sort the list in ascending order
    ans.sort()
    
    # Initialize count with the largest element in the sorted list
    count = ans[-1]
    
    # Iterate through the list from the second largest element to the first
    for i in range(n - 2, -1, -1):
        # If the current element is less than the next element, add it to count
        if ans[i] < ans[i + 1]:
            count += ans[i]
        else:
            # If the current element is not less, decrement it until it is less than the next element
            while ans[i] >= ans[i + 1]:
                ans[i] -= 1
            # If the decremented value is still positive, add it to count
            if ans[i] > 0:
                count += ans[i]
    
    # Print the final count
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
