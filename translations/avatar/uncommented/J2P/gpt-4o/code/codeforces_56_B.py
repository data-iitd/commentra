def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    len_a = int(data[0])
    a = list(map(int, data[1:len_a + 1]))
    
    l = 0
    r = 0
    flag = False
    isTrue = False
    
    for i in range(len_a):
        if a[i] != i + 1 and not flag:
            l = i + 1
            flag = True
            continue
        if a[i] != i + 1 and flag:
            r = i + 1
            if a[r - 1] - a[r - 2] > 0:
                isTrue = True
                break
    
    if not isTrue:
        print(f"{l} {r}")
    else:
        print("0 0")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
