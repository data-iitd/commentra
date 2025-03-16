def main():
    len_ = int(input())
    a = list(map(int, input().split()))
    
    l = 0
    r = 0
    flag = False
    is_true = False
    
    for i in range(len_):
        if a[i] != i + 1 and not flag:
            l = i + 1
            flag = True
            continue
        if a[i] != i + 1 and flag:
            r = i + 1
            if (a[r - 1] - a[r - 2] > 0):
                is_true = True
                break
    
    if not is_true:
        print(f"{l} {r}")
    else:
        print("0 0")

if __name__ == "__main__":
    main()
