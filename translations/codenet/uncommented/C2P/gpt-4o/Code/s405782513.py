def main():
    while True:
        try:
            c = list(map(int, input().split()))
            if len(c) != 3:
                break
        except EOFError:
            break
        
        card = [0] * 10
        count = 0
        sum_c = c[0] + c[1]
        
        for i in range(3):
            card[c[i] - 1] = 1
        
        for i in range(10):
            if card[i] == 0 and sum_c + (i + 1) <= 20:
                count += 1
        
        if count >= 4:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
