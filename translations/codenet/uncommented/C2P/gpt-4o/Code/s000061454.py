def main():
    while True:
        try:
            a, b, n = map(int, input().split())
        except EOFError:
            break
        
        a -= a // b * b
        total_sum = 0
        
        for i in range(1, n + 1):
            a *= 10
            for j in range(9, -1, -1):
                if b * j <= a:
                    break
            a -= b * j
            total_sum += j
        
        print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
