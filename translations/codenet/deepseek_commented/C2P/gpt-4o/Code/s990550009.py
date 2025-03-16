def main():
    n = int(input())  # Read the number of elements
    a = list(map(int, input().split()))  # Read the elements into the list
    cnt = 1
    isup = None
    issame = False
    
    # Step 2: Initialization and Condition Check
    if a[0] < a[1]:
        isup = True  # Set isup to true if the first two elements indicate an increasing trend
    elif a[0] > a[1]:
        isup = False  # Set isup to false if the first two elements indicate a decreasing trend
    else:
        issame = True  # Set issame to true if the first two elements are the same
    
    # Step 3: Loop Through Elements
    for i in range(1, n - 1):
        if issame:
            if a[i] != a[i + 1]:
                issame = False  # If the sequence is not consistent, reset issame and set the new trend
                if a[i] < a[i + 1]:
                    isup = True
                else:
                    isup = False
        else:
            if isup and a[i] <= a[i + 1]:
                continue  # Continue if the current trend is increasing and the next element is greater or equal
            elif not isup and a[i] >= a[i + 1]:
                continue  # Continue if the current trend is decreasing and the next element is less or equal
            else:
                if i + 2 < n:
                    if a[i + 1] < a[i + 2]:
                        isup = True  # Update the trend if the next element indicates a change
                    elif a[i + 1] > a[i + 2]:
                        isup = False
                    else:
                        issame = True
                    cnt += 1  # Increment the count for a new segment
                else:
                    cnt += 1  # Increment the count for the last segment
                    break
    
    # Step 4: Output the Result
    print(cnt)  # Print the count of segments

if __name__ == "__main__":
    main()

# <END-OF-CODE>
