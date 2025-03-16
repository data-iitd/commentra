
import sys
import os
import io
import struct
import array
import bisect

def read_long_lines(times):
    result = []
    reader = io.BufferedReader(io.FileIO(0))
    buffer = io.BytesIO()
    read_bytes = 2

    for i in range(times):
        while True:
            read_buf = reader.read(1024)
            read_bytes += len(read_buf)
            if not read_buf:
                print("EOF")
                break
            buffer.write(read_buf)
            if not reader.read(1):
                result.append(buffer.getvalue().decode())
                buffer.truncate(0)
                break

    os.lseek(0, -read_bytes, os.SEEK_CUR)
    return result

class Console:
    def __init__(self):
        self.writer = io.BufferedWriter(io.FileIO(1, "w"))

    def printf(self, format, *a):
        self.writer.write(format.encode() % a)

    def println(self, s):
        self.writer.write(s.encode())
        self.writer.write(b"\n")

    def close(self):
        self.flush()

    def flush(self):
        self.writer.flush()

def print_list(list):
    con = Console()
    try:
        for i, v in enumerate(list):
            if i == 0:
                con.printf("%d", v)
            else:
                con.printf(" %d", v)
        con.println("")
    finally:
        con.flush()

if __name__ == "__main__":
    con = Console()
    try:
        m = {}
        lines = read_long_lines(4)
        a = lines[1].split()
        for i in a:
            m[int(i)] = True
        result = []
        b = lines[3].split()
        for i in b:
            if int(i) in m:
                del m[int(i)]
            else:
                m[int(i)] = True
        for k in sorted(m.keys()):
            result.append(k)
        print_list(result)
    finally:
        con.flush()

