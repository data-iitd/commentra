# FileName:     the_number_of_inversions_fix.py
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900

def sort(a, left, middle, right):
    l_arr = a[left:middle] + [float('inf')]
    r_arr = a[middle:right] + [float('inf')]
    cnt = 0
    l = 0
    r = 0
    for i in range(left, right):
        if l_arr[l] <= r_arr[r]:
            a[i] = l_arr[l]
            l += 1
        else:
            a[i] = r_arr[r]
            cnt += (middle - left - l)
            r += 1
    return cnt

def merge(a, left, right):
    if left + 1 < right:
        middle = (left + right) // 2
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        x3 = sort(a, left, middle, right)
        return x1 + x2 + x3
    else:
        return 0

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    print(merge(a, 0, n))

# <END-OF-CODE>
