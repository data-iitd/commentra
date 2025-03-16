import sys

def check_no(brr):
    val = 0
    for i in brr:
        if i == 1:
            val += 1
    return val

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    max_count = float('-inf')
    
    for i in range(n):
        for j in range(i, n):
            brr = arr[:]
            for k in range(i, j + 1):
                brr[k] = 1 - brr[k]
            count = check_no(brr)
            if count > max_count:
                max_count = count
    
    if n == 1:
        print(0 if arr[0] == 1 else 1)
    else:
        print(max_count)

if __name__ == "__main__":
    main()
