import sys

def out(*args):
    print(*args)

def get_int():
    return int(sys.stdin.readline().strip())

def get_string():
    return sys.stdin.readline().strip()

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def asub(a, b):
    return a - b if a > b else b - a

def abs(a):
    return a if a >= 0 else -a

class Shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    shops = []
    
    for _ in range(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        shops.append(Shop(a, b))
    
    # Sort shops by price (a)
    shops.sort(key=lambda shop: shop.a)

    total = 0
    for shop in shops:
        n = min(shop.b, M)
        total += n * shop.a
        M -= n
        if M == 0:
            break
    
    out(total)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
