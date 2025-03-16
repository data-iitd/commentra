
import sys

class Main:
    # Default buffer size if none is provided
    DEFAULT_BUFFER_SIZE = 5

    # Instance variables for buffer size, buffer array, read positions, and EOF flag
    def __init__(self, input, bufferSize):
        self.bufferSize = bufferSize
        self.buffer = bytearray(bufferSize)
        self.posRead = 0
        self.bufferPos = 0
        self.foundEof = False
        self.input = input

    # Method to read a single byte from the buffer or input stream
    def read(self):
        if self.needsRefill():
            if self.foundEof:
                return -1
            self.refill()
        return self.posRead < self.bufferPos and ord(self.buffer[self.posRead]) or -1

    # Method to check how many bytes are available to read
    def available(self):
        available = self.input.available()
        if self.needsRefill():
            return available
        return self.bufferPos - self.posRead + available

    # Method to read a block of bytes from the input stream
    def readBlock(self):
        self.pushRefreshData()
        cloned = bytearray(self.bufferSize)
        if self.bufferPos > 0:
            cloned[:self.bufferPos] = self.buffer[:self.bufferPos]
        self.refill()
        return cloned

    # Method to check if the buffer needs to be refilled
    def needsRefill(self):
        return self.posRead == self.bufferPos

    # Method to refill the buffer with data from the input stream
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

    # Method to push remaining data in the buffer to the front for further processing
    def pushRefreshData(self):
        length = self.bufferPos - self.posRead
        self.buffer[:length] = self.buffer[self.posRead:self.bufferPos]
        self.bufferPos = length
        self.posRead = 0
        self.refill()

    # Method to close the input stream
    def close(self):
        if self.input:
            try:
                self.input.close()
            finally:
                self.input = None

    # Main method to execute the program
    @staticmethod
    def main():
        try:
            bufferSize = int(input("Enter buffer size: "))
            inputString = input("Enter input string: ")
            bufferedReader = Main(inputString.encode(), bufferSize)
            readByte = bufferedReader.read()
            while readByte!= -1:
                sys.stdout.write(chr(readByte))
                readByte = bufferedReader.read()
            bufferedReader.close()
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    Main.main()

