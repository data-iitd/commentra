import sys

def main():
    infile = sys.stdin.read
    data = infile().splitlines()
    
    arr = list(data[0])
    N = len(arr)
    K = int(data[1])
    res = 0
    
    for k in range(K):
        input_str = data[k + 2]
        a = 0
        b = 0
        
        for i in range(N):
            if arr[i] == input_str[0]:
                a += 1
            elif arr[i] == input_str[1]:
                b += 1
            else:
                res += min(a, b)
                a = b = 0
        
        res += min(a, b)
    
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
