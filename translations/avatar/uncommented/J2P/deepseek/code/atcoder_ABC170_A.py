import sys

def main():
    input_line = sys.stdin.readline().strip()
    input_array = input_line.split()
    result = 0
    for str in input_array:
        result += 1
        if str == '0':
            break
    print(result)

if __name__ == "__main__":
    main()
