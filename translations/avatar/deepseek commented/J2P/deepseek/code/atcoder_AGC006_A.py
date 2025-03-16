import sys

def get_fail(b, m):
    f = [0] * (m + 1)
    j = 0
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j
    return f

def main():
    # Read input values
    n = int(input().strip())
    s1 = input().strip()
    str = input().strip()
    
    # Construct a combined string
    cnt = 0
    b = [0] * (2 * n + 1)
    for i in range(n):
        cnt += 1
        b[cnt] = str[i]
    for i in range(n):
        cnt += 1
        b[cnt] = s1[i]
    
    # Compute the failure array for the combined string
    f = get_fail(b, cnt)
    
    # Calculate the result based on the failure array
    len_ = min(f[cnt], min(n, n))
    
    # Print the result
    print(2 * n - len_)

if __name__ == "__main__":
    main()
