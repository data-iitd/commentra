def main():
    j = int(input())

    for _ in range(j):
        a = int(input())
        b = int(input())
        c = int(input())

        max_value = a
        k = 0
        if max_value <= b:
            max_value = b
            k = 1
        if max_value <= c:
            max_value = c
            k = 2

        max_value = max_value * max_value
        a = a * a
        b = b * b
        c = c * c
        
        if k == 0 and max_value == b + c:
            print("YES")
        elif k == 1 and max_value == a + c:
            print("YES")
        elif k == 2 and max_value == a + b:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
