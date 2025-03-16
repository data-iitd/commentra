
import sys

class city:
    def __init__(self, prefecture, position, year):
        self.prefecture = prefecture
        self.position = position
        self.year = year

    def __lt__(self, other):
        return self.year < other.year

class cities(list):
    def __init__(self, prefecture, position, year):
        self.prefecture = prefecture
        self.position = position
        self.year = year

    def __lt__(self, other):
        return self.year < other.year

def main():
    n, m = map(int, sys.stdin.readline().split())
    h = {}
    for i in range(m):
        x, y = map(int, sys.stdin.readline().split())
        _, exists = h.get(x, None)
        if not exists:
            h[x] = cities(x, i, y)
        else:
            h[x].append(city(x, i, y))

    results = []
    for _, v in h.items():
        v.sort()
        for idx, ci in enumerate(v):
            results.append(str(ci.prefecture).zfill(6) + str(idx+1).zfill(6))

    print("\n".join(results))

if __name__ == "__main__":
    main()

