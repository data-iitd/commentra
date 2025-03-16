import sys

def main():
    try:
        x = input().split()
        a = int(x[0])
        b = int(x[1])
        c = a - b * 2
        if c < 0:
            c = 0
        print(c)
    except:
        # Handle exceptions (not implemented in this code)
        pass

if __name__ == "__main__":
    main()

