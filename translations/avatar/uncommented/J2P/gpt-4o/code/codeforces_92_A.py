def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    
    i = 1
    req = 1
    
    while k - req >= 0:
        if k - req >= 0:
            k -= req
        else:
            break
        i += 1
        if i % n != 0:
            req = i % n
        else:
            req = n
            
    print(k)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
