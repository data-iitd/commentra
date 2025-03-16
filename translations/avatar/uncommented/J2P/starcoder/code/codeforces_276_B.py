
import sys

def main():
    input = sys.stdin.readline()
    str = input.strip()
    map = {}
    oddCount = 0
    for i in range(len(str)):
        ch = str[i]
        if ch in map:
            map[ch] += 1
        else:
            map[ch] = 1
    for entry in map.items():
        if entry[1] % 2!= 0:
            oddCount += 1
    if oddCount <= 1 or oddCount % 2!= 0:
        print("First")
    else:
        print("Second")

if __name__ == "__main__":
    main()

