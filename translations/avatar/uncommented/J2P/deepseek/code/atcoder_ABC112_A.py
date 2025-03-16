import sys

def read(len):
    str_list = []
    for _ in range(len):
        str_list.append(sys.stdin.readline().strip())
    return str_list

def main():
    n = int(read(1)[0])
    if n == 1:
        print("Hello World")
    else:
        strs = read(2)
        print(int(strs[0]) + int(strs[1]))

if __name__ == "__main__":
    main()
