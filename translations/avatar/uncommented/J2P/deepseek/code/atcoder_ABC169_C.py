import sys

def main():
    a = int(input())
    b = input()
    b_str = ""
    for char in b:
        if char != '.':
            b_str += char
        else:
            break
    b_int = int(b_str)
    result = (a * b_int) // 100
    print(result)

if __name__ == "__main__":
    main()
