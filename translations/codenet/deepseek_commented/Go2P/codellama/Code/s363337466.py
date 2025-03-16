
def walk_on_multiplication_table(num):
    div = 0
    for i in range(int(num**0.5), 1, -1):
        if num % i == 0:
            div = i
            break
    if div == 0:
        return num - 1
    return div + num // div - 2

def main():
    a = int(input())
    print(walk_on_multiplication_table(a))

