
# Go:
package main

import (
	"fmt"
	"sort"
	"strings"
)

# Define a struct to represent a city with its prefecture, year, and position
class City:
    def __init__(self, prefecture, year, position):
        self.prefecture = prefecture
        self.year = year
        self.position = position

# Define a slice of city pointers for sorting
class Cities(list):
    def __init__(self, cities):
        super().__init__(cities)

# Define a map where the key is an integer (prefecture) and the value is a slice of cities
class CMap(dict):
    def __init__(self, cmap):
        super().__init__(cmap)

def main():
    n, m = map(int, input().split())
    h = CMap()
    for i in range(m):
        x, y = map(int, input().split())
        if x not in h:
            h[x] = Cities([City(x, y, i)])
        else:
            h[x].append(City(x, y, i))
    results = [""] * m
    for v in h.values():
        v.sort(key=lambda x: x.year)
        for idx, ci in enumerate(v):
            results[ci.position] = f"{ci.prefecture:06d}{idx+1:06d}"
    print("\n".join(results))

# END-OF-CODE