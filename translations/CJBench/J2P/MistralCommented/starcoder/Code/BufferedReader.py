
import sys
import io

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
        self.input = io.BytesIO(input)
        # Check if the stream is empty or already closed
        if self.input.getbuffer().nbytes == 0:
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
        return self.buffer[self.posRead] if self.posRead < self.bufferPos else -1

    # Get the number of bytes available to read from the input stream
    def available(self):
        # Get the number of bytes available from the input stream
        available = self.input.getbuffer().nbytes
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
            for i in range(self.bufferPos):
                cloned[i] = self.buffer[i]
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
            read = self.input.read(1)
            if read == b'':
                # If the end of the stream is reached, set the foundEof flag and break the loop
                self.foundEof = True
                break
            # Store the read byte in the buffer
            self.buffer[self.bufferPos] = read[0]
            self.bufferPos += 1

    # Save the current buffer position and number of bytes read, and refill the buffer
    def pushRefreshData(self):
        # Calculate the number of bytes read from the buffer
        length = self.bufferPos - self.posRead
        # Copy the contents of the buffer from the current position to the beginning of the buffer
        for i in range(length):
            self.buffer[i] = self.buffer[self.posRead + i]
        # Reset the buffer position and number of bytes read
        self.bufferPos = length
        self.posRead = 0
        # Refill the buffer
        self.refill()

    # Close the input stream
    def close(self):
        # Close the input stream, if it is not null
        if self.input!= None:
            try:
                self.input.close()
            finally:
                # Set the input stream to null
                self.input = None

# Main method to test the implementation
if __name__ == "__main__":
    try:
        # Read the buffer size from the standard input
        bufferSize = int(input())
        # Read the rest of the line from the standard input and discard it
        input()
        # Read a line from the standard input and convert it to a byte array
        inputString = input()
        inputBytes = inputString.encode()
        # Create a new instance of the Main class with the byte array input and the specified buffer size
        bufferedReader = Main(inputBytes, bufferSize)
        # Read bytes from the input stream and print them to the standard output until the end of the stream is reached
        readByte = bufferedReader.read()
        while readByte!= -1:
            print(chr(readByte), end='')
            readByte = bufferedReader.read()
        # Close the input stream
        bufferedReader.close()
    except Exception as e:
        # Print an error message if an error occurs
        print("An error occurred: " + str(e), file=sys.stderr)

