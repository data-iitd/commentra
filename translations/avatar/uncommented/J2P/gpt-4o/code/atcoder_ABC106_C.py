def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    str_value = data[0]
    k = int(data[1])
    c = list(str_value)
    n = len(str_value)
    
    for i in range(k):
        if c[i] == '1':
            if i == k - 1:
                print(1)
                return
        else:
            print(c[i])
            return

if __name__ == "__main__":
    main()

# <END-OF-CODE>
