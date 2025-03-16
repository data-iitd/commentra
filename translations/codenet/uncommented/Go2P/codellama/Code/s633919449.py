
import sys
import math

def main():
    N = int(sys.stdin.readline())

    switch = {
        2: "hon",
        4: "pon",
        5: "hon",
        7: "pon",
        9: "hon",
        0: "pon",
        1: "pon",
        6: "pon",
        8: "pon",
        3: "bon"
    }

    print(switch[N % 10])

if __name__ == "__main__":
    main()

