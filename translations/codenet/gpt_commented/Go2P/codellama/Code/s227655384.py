
import sys

def read_long_lines(times):
    result = []
    reader = sys.stdin.buffer.readline
    buffer = bytearray()
    read_bytes = 2

    for i in range(times):
        while True:
            read_buf = reader()
            read_bytes += len(read_buf) + 1
            if not read_buf:
                if read_bytes == 2:
                    sys.stdout.write("EOF\n")
                    break
                else:
                    return result, "Error reading from standard input"
            buffer.extend(read_buf)
            if not reader():
                result.append(buffer.decode())
                buffer.clear()
                break

    sys.stdin.seek(-read_bytes, 1)
    return result, None

def print_list(list):
    for i, item in enumerate(list):
        if i == 0:
            print(item, end="")
        else:
            print(" " + item, end="")
    print()

def main():
    m = {}
    lines, err = read_long_lines(4)
    if err:
        print(err)
        return
    a = lines[1].split()

    for i in a:
        m[int(i)] = None

    result = []
    b = lines[3].split()

    for i in b:
        n = int(i)
        if n in m:
            del m[n]
        else:
            m[n] = None

    for k in m:
        result.append(k)

    result.sort()

    print_list(result)

if __name__ == "__main__":
    main()

