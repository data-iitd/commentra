import sys

def read():
    return sys.stdin.readline().strip()

def main():
    a = int(read())
    b = int(read())

    ret = a + b

    if ret < (a - b):
        ret = a - b
    if ret < (a * b):
        ret = a * b

    print(ret)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
