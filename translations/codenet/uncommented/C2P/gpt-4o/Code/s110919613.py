def main():
    while True:
        an = [0] * 20
        a1 = [0] * 6
        a2 = [0] * 6
        
        an[0], L = map(int, input().split())
        if L == 0:
            break
        
        aj = an[0]
        end = 0
        for k in range(1, 21):
            for i in range(L - 1, -1, -1):
                a1[i] = aj % 10
                a2[i] = aj % 10
                aj //= 10
            
            for i in range(1, L):
                for j in range(1, L):
                    if a1[j - 1] < a1[j]:
                        a1[j - 1], a1[j] = a1[j], a1[j - 1]
                    if a2[j - 1] > a2[j]:
                        a2[j - 1], a2[j] = a2[j], a2[j - 1]
            
            d = 1
            max_val = 0
            min_val = 0
            for i in range(L - 1, -1, -1):
                max_val += (a1[i] % 10) * d
                min_val += (a2[i] % 10) * d
                d *= 10
            
            def_val = max_val - min_val
            for i in range(k):
                if def_val == an[i]:
                    print(f"{i} {def_val} {k - i}")
                    end = 1
                    break
            
            if end == 1:
                break
            
            an[k] = def_val
            aj = def_val

if __name__ == "__main__":
    main()

# <END-OF-CODE>
