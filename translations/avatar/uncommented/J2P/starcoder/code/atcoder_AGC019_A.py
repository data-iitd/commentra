
import sys

def main():
    Q = int(raw_input())
    H = int(raw_input())
    S = int(raw_input())
    D = int(raw_input())
    N = int(raw_input())
    onePrice = min(min(Q*4, H*2), S)
    if onePrice <= D/2:
        print N*onePrice
    else:
        print (N/2)*D + (N%2)*onePrice

if __name__ == "__main__":
    main()

