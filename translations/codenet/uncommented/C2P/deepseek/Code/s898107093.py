import sys

def main():
    n = int(input().strip())
    taro = 0
    hanako = 0
    for _ in range(n):
        t = input().strip()
        h = input().strip()
        if t < h:
            hanako += 3
        elif t > h:
            taro += 3
        else:
            taro += 1
            hanako += 1
    print(f"{taro} {hanako}")

if __name__ == "__main__":
    main()
