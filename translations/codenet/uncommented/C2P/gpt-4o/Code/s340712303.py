N = 2000
num1 = 0
math = [0] * (N + 1)

def main():
    global num1
    sum = 0

    math[0] = 1

    num1 = int(input())
    for _ in range(num1):
        a = int(input())
        sum += a
        for j in range(sum - a, -1, -1):
            if math[j] == 1:
                math[j + a] = 1

    num2 = int(input())
    for _ in range(num2):
        ans = int(input())
        print("yes" if math[ans] == 1 else "no")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
