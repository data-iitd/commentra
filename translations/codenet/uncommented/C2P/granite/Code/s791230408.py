
import sys

def main():
    j = int(input())

    for i in range(j):
        a, b, c = map(int, input().split())
        max_val = max(a, b, c)
        max_idx = a.index(max_val) if max_val in a else b.index(max_val) if max_val in b else c.index(max_val)
        max_val_squared = max_val ** 2
        a_squared = a[max_idx] ** 2
        b_squared = b[max_idx] ** 2
        c_squared = c[max_idx] ** 2
        if max_idx == 0 and max_val_squared == b_squared + c_squared:
            print("YES")
        elif max_idx == 1 and max_val_squared == a_squared + c_squared:
            print("YES")
        elif max_idx == 2 and max_val_squared == a_squared + b_squared:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

