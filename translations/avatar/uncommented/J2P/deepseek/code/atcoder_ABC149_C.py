import math

def main():
    x = int(input())
    if x != 2 and x % 2 == 0:
        x += 1
    while True:
        i = 3
        sqrt_num = math.sqrt(x)
        while i <= sqrt_num:
            if x % i == 0:
                break
            i += 2
        if i > sqrt_num:
            break
        x += 2
    print(x)

if __name__ == "__main__":
    main()
