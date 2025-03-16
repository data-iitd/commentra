
import sys
import io

class Main:
    # Default buffer size
    DEFAULT_BUFFER_SIZE = 5

    # Fields to manage the buffer and input stream
    bufferSize = 0
    buffer = []
    posRead = 0
    bufferPos = 0
    foundEof = False
    input = None

    # Constructor that takes a byte array and buffer size
    def __init__(self, input, bufferSize):
        self.input = io.BytesIO(input)
        self.bufferSize = bufferSize
        self.buffer = [0] * bufferSize

    # Reads a single byte from the buffer or input stream
    def read(self):
        if self.needsRefill():
            if self.foundEof:
                return -1
            self.refill()
        return self.posRead < self.bufferPos and ord(self.buffer[self.posRead]) or -1

    # Returns the number of bytes available in the buffer or input stream
    def available(self):
        available = self.input.available()
        if self.needsRefill():
            return available
        return self.bufferPos - self.posRead + available

    # Reads a block of data from the buffer and refills it if necessary
    def readBlock(self):
        self.pushRefreshData()
        cloned = bytearray(self.bufferSize)
        if self.bufferPos > 0:
            cloned[:self.bufferPos] = self.buffer[:self.bufferPos]
        self.refill()
        return cloned

    # Checks if the buffer needs to be refilled
    def needsRefill(self):
        return self.posRead == self.bufferPos

    # Refills the buffer from the input stream
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

    # Refills the buffer and pushes the read data to the front
    def pushRefreshData(self):
        length = self.bufferPos - self.posRead
        self.buffer[:length] = self.buffer[self.posRead:self.bufferPos]
        self.bufferPos = length
        self.posRead = 0
        self.refill()

    # Closes the input stream
    def close(self):
        if self.input:
            try:
                self.input.close()
            except:
                pass
            finally:
                self.input = None

# Main method to read input from the console, initialize the buffer, and read/print characters
if __name__ == "__main__":
    bufferSize = int(input())
    inputString = input()
    bufferedReader = Main(inputString.encode(), bufferSize)
    readByte = bufferedReader.read()
    while readByte!= -1:
        sys.stdout.write(chr(readByte))
        readByte = bufferedReader.read()
    bufferedReader.close()

