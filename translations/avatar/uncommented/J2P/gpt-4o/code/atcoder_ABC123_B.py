from collections import defaultdict

def main():
    a = [0] * 5
    r = [0] * 5
    map = {}
    
    for i in range(len(a)):
        a[i] = int(input())
        r[i] = a[i] % 10
        b = 10
        if r[i] != 0:
            b = 10 - r[i]
            map[b] = a[i]
    
    ans = 0
    if len(map) == 0:
        ans = sum(a)
        print(ans)
        return
    
    last = map[max(map)]
    idx = 0
    for i in range(len(a)):
        if a[i] == last:
            idx = i
    
    for i in range(len(a)):
        if i != idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])
    
    ans += last
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
