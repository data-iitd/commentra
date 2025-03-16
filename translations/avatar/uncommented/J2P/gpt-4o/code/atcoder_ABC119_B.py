def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    N = int(data[0])
    x = []
    u = []
    
    for i in range(1, N + 1):
        value, currency = data[i].split()
        x.append(float(value))
        u.append(currency)
    
    print(solve(x, u))

def solve(x, u):
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
