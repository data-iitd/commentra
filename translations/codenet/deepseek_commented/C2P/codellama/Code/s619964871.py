
#!/usr/bin/env python3

#
# FileName:     the_number_of_inversions_fix
# CreatedDate:  2020-06-05 16:25:10 +0900
# LastModified: 2020-07-06 22:22:35 +0900
#

import sys

def sort(a, left, middle, right):
    l_arr = a[left:middle]
    r_arr = a[middle:right]
    l_arr.append(sys.maxsize)
    r_arr.append(sys.maxsize)
    l = 0
    r = 0
    cnt = 0
    for i in range(left, right):
        if l_arr[l] <= r_arr[r]:
            a[i] = l_arr[l]
            l += 1
        else:
            a[i] = r_arr[r]
            r += 1
            cnt += middle - left - l
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

def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(merge(a, 0, n))

if __name__ == "__main__":
    main()

