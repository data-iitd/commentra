def main():
    count = [0] * 4
    for _ in range(3):
        a, b = map(int, input().split())
        count[a - 1] += 1
        count[b - 1] += 1
    
    s = 1
    for c in count:
        s *= c
    
    if s == 4:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
