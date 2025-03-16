
import sys
import os
import io
import bufio
import struct
import array
import math
import re
import time
import random
import copy
import bisect
import collections
import itertools
import heapq
import functools
import operator
import queue
import threading
import subprocess
import unittest

def ReadLongLines(times):
    result = []
    reader = bufio.NewReader(sys.stdin)
    buffer = io.BytesIO()
    readBytes = 2
    for i in range(times):
        while True:
            readBuf = reader.readline()
            readBytes += len(readBuf) + 1
            if not readBuf:
                print("EOF")
                break
            buffer.write(readBuf)
            # end of line
            if not readBuf.endswith(b"\n"):
                result.append(buffer.getvalue().decode())
                buffer.truncate(0)
                reader = bufio.NewReader(sys.stdin)
                break
    # 先 reading and keeping it in the buffer
    sys.stdin.seek(-reader.buffer.tell(), os.SEEK_CUR)
    return result

class Console:
    def __init__(self):
        self.writer = bufio.BufferedWriter(sys.stdout)

    def Printf(self, format, *a):
        self.writer.write(format.encode())
        self.writer.write(b" ")
        self.writer.write(str(a[0]).encode())
        self.writer.write(b"\n")

    def Println(self, s):
        self.writer.write(s.encode())
        self.writer.write(b"\n")

    def Close(self):
        self.Flush()

    def Flush(self):
        self.writer.flush()

def PrintList(list):
    con = Console()
    for i in range(len(list)):
        if i == 0:
            con.Printf("%d", list[i])
        else:
            con.Printf(" %d", list[i])
    con.Println("")

if __name__ == "__main__":
    con = Console()
    lines = ReadLongLines(4)
    a = lines[1].split()
    m = set()
    for i in range(len(a)):
        n = int(a[i])
        m.add(n)

    result = []
    b = lines[3].split()
    for i in range(len(b)):
        n = int(b[i])
        if n in m:
            m.remove(n)
        else:
            m.add(n)
    result = list(m)
    result.sort()
    for k in result:
        con.Printf("%d\n", k)

