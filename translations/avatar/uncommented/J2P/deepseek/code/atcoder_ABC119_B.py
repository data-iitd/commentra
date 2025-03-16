def solve(x, u):
    return sum(xi * (380000.0 if ui == "BTC" else 1) for xi, ui in zip(x, u))

def main():
    n = int(input())
    x = []
    u = []
    for _ in range(n):
        xi, ui = input().split()
        x.append(float(xi))
        u.append(ui)
    print(solve(x, u))

if __name__ == "__main__":
    main()
