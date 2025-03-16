import sys

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_scanner = sys.stdin.readline
    out_writer = sys.stdout.write

    s = in_scanner().replace("BC", "D")
    cnt = 0
    tmp = 0
    for char in s:
        if char == 'A':
            tmp += 1
        elif char == 'D':
            cnt += tmp
        else:
            tmp = 0
    out_writer(str(cnt) + '\n')

if __name__ == "__main__":
    main()
