import sys

N = 200 + 10
f = [0] * N
b = [''] * N

# Computes the failure array for the given pattern
def get_fail(b, m):
    j = 0
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s1 = data[1]
    str_ = data[2]
    
    # Construct a combined string
    cnt = 0
    for i in range(n):
        b[cnt + 1] = str_[i]
        cnt += 1
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1
    
    # Compute the failure array for the combined string
    get_fail(b, cnt)
    
    # Calculate the result based on the failure array
    length = min(f[cnt], min(n, n))
    
    # Print the result
    print(2 * n - length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
