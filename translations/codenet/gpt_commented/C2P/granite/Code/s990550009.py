
# Read the number of elements
n = int(input())

# Read the elements into the array
a = list(map(int, input().split()))

# Determine the initial trend based on the first two elements
if a[0] < a[1]:
    isup = True  # Initial trend is increasing
elif a[0] > a[1]:
    isup = False  # Initial trend is decreasing
else:
    issame = True  # Initial elements are the same

# Iterate through the array to count segments
cnt = 1
for i in range(1, n - 1):
    # Handle the case where previous elements are the same
    if issame:
        if a[i]!= a[i + 1]:
            issame = False  # Found a different value, update flag
            if a[i] < a[i + 1]:
                isup = True  # New trend is increasing
            else:
                isup = False  # New trend is decreasing
    else:
        # Check if the current trend is maintained
        if isup and a[i] <= a[i + 1]:
            # Trend is increasing and maintained
            pass
        elif not isup and a[i] >= a[i + 1]:
            # Trend is decreasing and maintained
            pass
        else:
            # Trend has changed
            if i + 2 < n:
                # Determine the new trend based on the next element
                if a[i + 1] < a[i + 2]:
                    isup = True  # New trend is increasing
                elif a[i + 1] > a[i + 2]:
                    isup = False  # New trend is decreasing
                else:
                    issame = True  # New elements are the same
                cnt += 1  # Increment the segment count
            else:
                cnt += 1  # Increment the segment count for the last element
                break  # Exit the loop as we reached the end

# Output the total number of segments
print(cnt)

