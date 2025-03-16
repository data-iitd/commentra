size = 100001

def main():
    n = int(input())
    t = int(input())
    mem = [0] * size
    
    for _ in range(n):
        l = int(input())
        r = int(input())
        mem[l] += 1
        mem[r] -= 1
    
    ans = mem[0]
    for i in range(1, t + 1):
        mem[i] += mem[i - 1]
        if ans < mem[i]:
            ans = mem[i]
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
