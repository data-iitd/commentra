
# <START-OF-CODE>

def main():
    while True:
        n, x = map(int, input().split())
        if n == 0 and x == 0:
            break
        c = 0
        for i in range(1, n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    if i+j+k == x:
                        c += 1
        print(c)

if __name__ == '__main__':
    main()

# 