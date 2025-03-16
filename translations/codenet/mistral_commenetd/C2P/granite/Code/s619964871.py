
# Python code to count inversions in an array using merge-sort algorithm

def merge(a, left, right):
    if left+1 < right:
        middle = (left+right)//2
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        x3 = sort(a, left, middle, right)
        return x1+x2+x3
    else:
        return 0

def sort(a, left, middle, right):
    l_arr = a[left:middle]
    r_arr = a[middle:right]
    l_arr.append(float('inf'))
    r_arr.append(float('inf'))
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
            cnt += middle-left-l
    return cnt

def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(merge(a, 0, n))

if __name__ == "__main__":
    main()

