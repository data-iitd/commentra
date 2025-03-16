# <START-OF-CODE>

# Declare variables
n = 0
a = []
cnt = 1
isup = False
issame = False

# Read the number of elements
n = int(input())

# Read the elements into the array
for i in range(n):
    a.append(int(input()))

# Determine the initial trend based on the first two elements
if a[0] < a[1]:
    isup = True
elif a[0] > a[1]:
    isup = False
else:
    issame = True

# Iterate through the array to count segments
for i in range(1, n - 1):
    # Handle the case where previous elements are the same
    if issame:
        if a[i]!= a[i + 1]:
            issame = False
            if a[i] < a[i + 1]:
                isup = True
            else:
                isup = False
    else:
        # Check if the current trend is maintained
        if isup and a[i] <= a[i + 1]:
            # Trend is increasing and maintained
            ;
        elif not isup and a[i] >= a[i + 1]:
            # Trend is decreasing and maintained
            ;
        else:
            # Trend has changed
            if i + 2 < n:
                # Determine the new trend based on the next element
                if a[i + 1] < a[i + 2]:
                    isup = True
                elif a[i + 1] > a[i + 2]:
                    isup = False
                else:
                    issame = True
                cnt += 1
            else:
                cnt += 1
                break

# Output the total number of segments
print(cnt)

# 