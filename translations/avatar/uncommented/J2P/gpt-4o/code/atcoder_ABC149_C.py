import math

def main():
    x = int(input())
    if x != 2 and x % 2 == 0:
        x += 1
    while True:
        sqrt_num = math.sqrt(x)
        for i in range(3, int(sqrt_num) + 1, 2):
            if x % i == 0:
                break
        else:
            break
        x += 2
    print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
