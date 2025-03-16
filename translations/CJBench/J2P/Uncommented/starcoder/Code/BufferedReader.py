
import sys
import io
import re

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
        return self.posRead < self.bufferPos and self.buffer[self.posRead] or -1

    def available(self):
        available = self.input.available()
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
            read = self.input.read()
            if read == -1:
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
        if self.input!= None:
            try:
                self.input.close()
            finally:
                self.input = None

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()

if __name__ == "__main__":
    try:
        with Main(io.BytesIO(sys.stdin.buffer.read()), int(input())) as bufferedReader:
            print("Reading byte-by-byte:")
            readByte = bufferedReader.read()
            while readByte!= -1:
                print(chr(readByte), end="")
                readByte = bufferedReader.read()
    except Exception as e:
        print("An error occurred: " + str(e), file=sys.stderr)

