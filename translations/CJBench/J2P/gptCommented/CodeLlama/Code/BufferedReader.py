
import io
import sys

class Main:
    # Default buffer size if none is provided
    DEFAULT_BUFFER_SIZE = 5

    # Instance variables for buffer size, buffer array, read positions, and EOF flag
    bufferSize = 0
    buffer = []
    posRead = 0
    bufferPos = 0
    foundEof = False
    input = None

    # Constructor that initializes the input stream from a byte array
    def __init__(self, input, bufferSize):
        self.input = io.BytesIO(input)
        # Check if the input stream is empty or closed
        if self.input.readable() == False:
            raise Exception("Empty or already closed stream provided")
        self.bufferSize = bufferSize # Set the buffer size
        self.buffer = [0] * bufferSize # Initialize the buffer array

    # Method to read a single byte from the buffer or input stream
    def read(self):
        # Check if the buffer needs to be refilled
        if self.needsRefill():
            # If EOF has been found, return -1 to indicate no more data
            if self.foundEof:
                return -1
            self.refill() # Refill the buffer
        # Return the next byte from the buffer, or -1 if no more data
        return self.posRead < self.bufferPos and self.buffer[self.posRead] or -1

    # Method to check how many bytes are available to read
    def available(self):
        available = self.input.readable() # Get available bytes from the input stream
        # If the buffer needs to be refilled, return available bytes
        if self.needsRefill():
            return available
        # Return the total available bytes from the buffer and input stream
        return self.bufferPos - self.posRead + available

    # Method to read a block of bytes from the input stream
    def readBlock(self):
        self.pushRefreshData() # Ensure any remaining data in the buffer is pushed to the front
        cloned = [0] * self.bufferSize # Create a new byte array for the block
        # Copy data from the buffer to the new array if there are bytes available
        if self.bufferPos > 0:
            cloned[0:self.bufferPos] = self.buffer[0:self.bufferPos]
        self.refill() # Refill the buffer for the next read
        return cloned # Return the block of bytes read

    # Method to check if the buffer needs to be refilled
    def needsRefill(self):
        return self.posRead == self.bufferPos # Return true if all bytes have been read from the buffer

    # Method to refill the buffer with data from the input stream
    def refill(self):
        self.posRead = 0 # Reset the read position
        self.bufferPos = 0 # Reset the buffer position
        # Read bytes from the input stream until the buffer is full or EOF is reached
        while self.bufferPos < self.bufferSize:
            read = self.input.read(1) # Read a byte from the input stream
            if read == b'': # Check for EOF
                self.foundEof = True # Set EOF flag
                break # Exit the loop if EOF is reached
            self.buffer[self.bufferPos] = read # Store the byte in the buffer
            self.bufferPos += 1

    # Method to push remaining data in the buffer to the front for further processing
    def pushRefreshData(self):
        length = self.bufferPos - self.posRead # Calculate remaining data length
        self.buffer[0:length] = self.buffer[self.posRead:self.bufferPos] # Shift remaining data to the front
        self.bufferPos = length # Update the buffer position
        self.posRead = 0 # Reset the read position
        self.refill() # Refill the buffer with new data

    # Method to close the input stream
    def close(self):
        if self.input != None:
            try:
                self.input.close() # Close the input stream
            finally:
                self.input = None # Set input to None to avoid further access

    # Main method to execute the program
    def main(self):
        try:
            # Read the buffer size from user input
            bufferSize = int(input())
            # Read the input string from user input
            inputString = input()
            # Create an instance of Main with the input string as bytes
            bufferedReader = Main(inputString.encode(), bufferSize)
            readByte = 0
            # Read bytes from the bufferedReader and print them as characters
            while readByte != -1:
                readByte = bufferedReader.read()
                if readByte != -1:
                    print(chr(readByte), end='')
            bufferedReader.close() # Close the bufferedReader
        except Exception as e:
            # Handle any IO exceptions that occur during execution
            print("An error occurred: " + str(e))

if __name__ == "__main__":
    Main().main()
    print("