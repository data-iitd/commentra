
import sys

def debug(*args):
    print(*args, file=sys.stderr)

def print(*args):
    print(*args)

def get():
    pass

def getv(vec):
    for i in range(len(vec)):
        vec[i] = input()

if __name__ == "__main__":
    S = input()
    if S == "Sunny":
        print("Cloudy")
    elif S == "Cloudy":
        print("Rainy")
    else:
        print("Sunny")

