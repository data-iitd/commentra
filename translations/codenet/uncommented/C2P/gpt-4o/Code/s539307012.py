def main():
    n, x, min_value = map(int, input().split())
    x -= min_value
    for _ in range(1, n):
        m = int(input())
        x -= m
        if min_value > m:
            min_value = m
    print(n + x // min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
