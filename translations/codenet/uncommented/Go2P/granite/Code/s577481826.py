
import sys

def read():
    return sys.stdin.readline().rstrip()

def main():
    a = int(read())
    b = int(read())

    ret = a + b

    if ret < (a - b):
        ret = a - b
    if ret < (a * b):
        ret = a * b

    print(ret)

