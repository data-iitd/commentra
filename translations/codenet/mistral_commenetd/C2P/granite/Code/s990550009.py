
# Read the number of elements from the user
n = int(input())

# Read the elements of the array from the user
a = list(map(int, input().split()))

# Initialize variables
cnt = 1
isup = True if a[0] < a[1] else False if a[0] > a[1] else None
issame = False

# Check for increasing subsequences in the array
for i in range(1, n - 1):
    if issame is None:
        if a[i]!= a[i + 1]:
            issame = False if a[i] < a[i + 1] else True
            cnt += 1
    else:
        if isup and a[i] <= a[i + 1]:
            pass
        elif not isup and a[i] >= a[i + 1]:
            isup = False if a[i] < a[i + 1] else True
            issame = False
            cnt += 1
        else:
            if i + 2 < n:
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

# Print the number of increasing subsequences
print(cnt)

