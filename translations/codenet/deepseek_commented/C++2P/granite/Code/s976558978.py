

import sys

def main():
    fin = sys.stdin
    fout = sys.stdout
    a = int(fin.readline())
    b = int(fin.readline())
    if a < b:
        for _ in range(b):
            fout.write(str(a))
    else:
        for _ in range(a):
            fout.write(str(b))
    fout.write("\n")

if __name__ == "__main__":
    main()

