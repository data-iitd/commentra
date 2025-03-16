
import sys

class Main:
    # Declare constants and instance variables
    DEFAULT_BUFFER_SIZE = 5
    bufferSize = 0
    buffer = []
    posRead = 0
    bufferPos = 0
    foundEof = False
    input = None

    # Constructor for byte array input
    def __init__(self, input, bufferSize):
        self.input = input
        # Check if the stream is empty or already closed
        if self.input.available() == -1:
            raise Exception("Empty or already closed stream provided")
        # Initialize buffer size
        self.bufferSize = bufferSize
        # Initialize buffer
        self.buffer = [0] * bufferSize

    # Read a single byte from the input stream
    def read(self):
        # Check if the buffer needs to be refilled
        if self.needsRefill():
            # If end of file is reached, return -1
            if self.foundEof:
                return -1
            # Refill the buffer
            self.refill()
        # Return the next byte from the buffer
        return self.posRead < self.bufferPos and self.buffer[self.posRead] or -1

    # Get the number of bytes available to read from the input stream
    def available(self):
        # Get the number of bytes available from the input stream
        available = self.input.available()
        # If the buffer needs to be refilled, return the number of bytes available from the input stream
        if self.needsRefill():
            return available
        # Otherwise, return the number of bytes remaining in the buffer and the number of bytes available from the input stream
        return self.bufferPos - self.posRead + available

    # Read a block of bytes from the input stream into a byte array
    def readBlock(self):
        # Save the current buffer position and number of bytes read
        self.pushRefreshData()
        # Create a new byte array with the same size as the buffer
        cloned = [0] * self.bufferSize
        # Copy the contents of the buffer into the new byte array, if there are any
        if self.bufferPos > 0:
            cloned[:self.bufferPos] = self.buffer[:self.bufferPos]
        # Refill the buffer
        self.refill()
        # Return the cloned byte array
        return cloned

    # Check if the buffer needs to be refilled
    def needsRefill(self):
        # Return true if the number of bytes read from the buffer is equal to the number of bytes in the buffer
        return self.posRead == self.bufferPos

    # Refill the buffer with new data from the input stream
    def refill(self):
        # Reset the buffer position and number of bytes read
        self.posRead = 0
        self.bufferPos = 0
        # Read bytes from the input stream into the buffer until it is full or the end of the stream is reached
        while self.bufferPos < self.bufferSize:
            read = self.input.read()
            if read == -1:
                # If the end of the stream is reached, set the foundEof flag and break the loop
                self.foundEof = True
                break
            # Store the read byte in the buffer
            self.buffer[self.bufferPos] = read
            self.bufferPos += 1

    # Save the current buffer position and number of bytes read, and refill the buffer
    def pushRefreshData(self):
        # Calculate the number of bytes read from the buffer
        length = self.bufferPos - self.posRead
        # Copy the contents of the buffer from the current position to the beginning of the buffer
        self.buffer[:length] = self.buffer[self.posRead:self.posRead + length]
        # Reset the buffer position and number of bytes read
        self.bufferPos = length
        self.posRead = 0
        # Refill the buffer
        self.refill()

    # Close the input stream
    def close(self):
        # Close the input stream, if it is not null
        if self.input is not None:
            try:
                self.input.close()
            finally:
                # Set the input stream to null
                self.input = None

    # Main method to test the implementation
    def main(self):
        try:
            # Read the buffer size from the standard input
            bufferSize = int(input())
            # Read the rest of the line from the standard input and discard it
            input()
            # Read a line from the standard input and convert it to a byte array
            inputString = input()
            inputBytes = bytearray(inputString, "utf-8")
            # Create a new instance of the Main class with the byte array input and the specified buffer size
            bufferedReader = Main(inputBytes, bufferSize)
            # Read bytes from the input stream and print them to the standard output until the end of the stream is reached
            readByte = 0
            while readByte != -1:
                readByte = bufferedReader.read()
                if readByte != -1:
                    print(chr(readByte), end="")
            # Close the input stream
            bufferedReader.close()
        except Exception as e:
            # Print an error message if an error occurs
            print("An error occurred: " + str(e))

if __name__ == "__main__":
    Main().main()

