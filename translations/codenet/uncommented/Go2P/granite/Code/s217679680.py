
import sys

def main():
    arr = scanArrayInt()
    a, b = arr[0], arr[1]
    tap = 0
    consent = 1
    while consent < b:
        consent = consent + a - 1
        tap += 1
    print(tap)

def scanArrayInt():
    return list(map(int, input().split()))

