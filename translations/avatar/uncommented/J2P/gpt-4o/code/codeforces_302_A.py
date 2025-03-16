import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    arr = list(map(int, data[2:n+2]))
    
    res = []
    o = arr.count(1)
    e = n - o  # Since total elements are n, even count can be derived
    
    index = n + 2
    for _ in range(k):
        l = int(data[index])
        r = int(data[index + 1])
        index += 2
        
        if (r - l + 1) % 2 == 1:
            res.append("0")
        else:
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                res.append("1")
            else:
                res.append("0")
    
    print("\n".join(res))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
