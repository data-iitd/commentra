def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    x = []
    u = []
    
    for i in range(1, N + 1):
        x.append(float(data[i]))
        u.append(data[i + N])
    
    print(solve(x, u))

def solve(x, u):
    total = 0.0
    for i in range(len(x)):
        if u[i] == "JPY":
            total += x[i]
        else:
            total += x[i] * 380000
    return total

main()
