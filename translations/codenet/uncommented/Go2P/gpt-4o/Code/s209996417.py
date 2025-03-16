import math

def main():
    n, k = map(float, input().split())

    # n を k進数にした時に何桁になるか？
    # ex : 10 を 2進数 = 2^3 + 2^1 = 1010 => 4桁
    # 桁数は最上位の位で決まる。この場合2^3 <= 10 < 2^4 であるため 4になった
    # 抽象化すると k^x <= n < k^(x+1) を満たすxを見つけ x+1を出力する

    x = 0.0
    while True:
        under = math.pow(k, x)
        upper = math.pow(k, x + 1)

        if under <= n < upper:
            print(int(x + 1))
            return
        x += 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
