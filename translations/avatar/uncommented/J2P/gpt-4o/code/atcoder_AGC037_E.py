def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    K = int(data[1])
    S = data[2]
    
    first_time = True
    step = 1
    
    while K > 0:
        T = S[::-1]
        revU = (S + T)[::-1]
        s_dash = S
        
        for i in range(N, -1, -step):
            tmp = revU[i:i + N]
            if s_dash > tmp:
                s_dash = tmp
            else:
                if not first_time:
                    break
        
        if first_time:
            first_time = False
            if 2 ** K > N:
                c = s_dash[0]
                print(c * N)
                sys.exit(0)
        else:
            step += step
        
        K -= 1
        S = s_dash[::-1]
    
    print(S[::-1])

if __name__ == "__main__":
    main()
