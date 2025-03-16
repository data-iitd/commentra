
import sys
import os
import io
import bufio
import struct
import array
import bisect

def read_long_lines(times):
    result = []
    reader = bufio.NewReader(sys.stdin)
    buffer = io.BytesIO()
    read_bytes = 2
    for i in range(times):
        while True:
            read_buf = reader.readline()
            read_bytes += len(read_buf) + 1
            if not read_buf:
                print("EOF")
                break
            buffer.write(read_buf)
            # end of line
            if not read_buf.endswith(b"\n"):
                result.append(buffer.getvalue().decode())
                buffer.truncate(0)
                reader = bufio.NewReader(sys.stdin)
                break
    # 先 reading and keeping it in memory, so return to the original position
    sys.stdin.seek(-reader.buffer.tell(), os.SEEK_CUR)
    return result

class Console:
    def __init__(self):
        self.writer = bufio.BufferedWriter(sys.stdout)

    def printf(self, format, *a):
        self.writer.write(format.encode().format(*a))

    def println(self, s):
        self.writer.write(s.encode())
        self.writer.write(b"\n")

    def flush(self):
        self.writer.flush()

def print_list(list):
    con = Console()
    for i in range(len(list)):
        if i == 0:
            con.printf("%d", list[i])
        else:
            con.printf(" %d", list[i])
    con.println("")

if __name__ == "__main__":
    con = Console()
    lines = read_long_lines(4)
    # Create a map to store unique elements.
    m = {}
    # Split the second line into individual elements and add them to the map.
    a = lines[1].split()
    for i in range(len(a)):
        n = int(a[i])
        m[n] = True
    # Process the fourth line to toggle the presence of elements in the map.
    result = []
    b = lines[3].split()
    for i in range(len(b)):
        n = int(b[i])
        if n in m:
            del m[n]
        else:
            m[n] = True
    # Extract the unique elements from the map and sort them.
    for k in m:
        result.append(k)
    result.sort()
    # Print the sorted list of unique elements.
    for j in range(len(result)):
        con.printf("%d\n", result[j])
    con.flush()

