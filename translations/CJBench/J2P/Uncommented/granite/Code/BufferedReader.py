

import sys
import os
import io

class Main:
    def __init__(self, input, bufferSize):
        self.input = input
        self.bufferSize = bufferSize
        self.buffer = bytearray(bufferSize)
        self.posRead = 0
        self.bufferPos = 0
        self.foundEof = False

    def read(self):
        if self.needsRefill():
            if self.foundEof:
                return -1
            self.refill()
        return self.posRead < self.bufferPos and ord(self.buffer[self.posRead])

    def available(self):
        available = os.fstat(self.input.fileno()).st_size - self.input.tell()
        if self.needsRefill():
            return available
        return self.bufferPos - self.posRead + available

    def readBlock(self):
        self.pushRefreshData()
        cloned = bytearray(self.bufferSize)
        if self.bufferPos > 0:
            cloned[:self.bufferPos] = self.buffer[:self.bufferPos]
        self.refill()
        return cloned

    def needsRefill(self):
        return self.posRead == self.bufferPos

    def refill(self):
        self.posRead = 0
        self.bufferPos = 0
        while self.bufferPos < self.bufferSize:
            read = self.input.read(1)
            if not read:
                self.foundEof = True
                break
            self.buffer[self.bufferPos] = read
            self.bufferPos += 1

    def pushRefreshData(self):
        length = self.bufferPos - self.posRead
        self.buffer[:length] = self.buffer[self.posRead:self.bufferPos]
        self.bufferPos = length
        self.posRead = 0
        self.refill()

    def close(self):
        if self.input:
            try:
                self.input.close()
            finally:
                self.input = None

if __name__ == "__main__":
    bufferSize = int(input("Enter buffer size: "))
    inputString = input("Enter input string: ")
    bufferedReader = Main(io.BytesIO(inputString.encode()), bufferSize)
    print("Reading byte-by-byte:")
    readByte = bufferedReader.read()
    while readByte!= -1:
        print(chr(readByte), end="")
        readByte = bufferedReader.read()
    bufferedReader.close()

