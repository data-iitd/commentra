class City:
    def __init__(self, prefecture, year, position):
        self.prefecture = prefecture
        self.year = year
        self.position = position

class Cities(list):
    def sort(self):
        super().sort(key=lambda city: city.year)

def main():
    n, m = map(int, input().split())
    h = {}
    
    for i in range(m):
        x, y = map(int, input().split())
        if x not in h:
            h[x] = Cities([City(x, y, i)])
        else:
            h[x].append(City(x, y, i))

    results = [""] * m

    for v in h.values():
        v.sort()
        for idx, ci in enumerate(v):
            results[ci.position] = f"{ci.prefecture:06d}{idx + 1:06d}"

    print("\n".join(results))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
