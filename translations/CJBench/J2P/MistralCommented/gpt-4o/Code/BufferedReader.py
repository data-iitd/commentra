import io

class Main:
    # Declare constants and instance variables
    DEFAULT_BUFFER_SIZE = 5

    def __init__(self, input_data, buffer_size):
        if isinstance(input_data, bytes):
            self.input = io.BytesIO(input_data)
        else:
            self.input = input_data
        
        # Check if the stream is empty or already closed
        if self.input.readable() is False:
            raise IOError("Empty or already closed stream provided")
        
        # Initialize buffer size
        self.buffer_size = buffer_size
        # Initialize buffer
        self.buffer = bytearray(buffer_size)
        self.pos_read = 0
        self.buffer_pos = 0
        self.found_eof = False

    # Read a single byte from the input stream
    def read(self):
        # Check if the buffer needs to be refilled
        if self.needs_refill():
            # If end of file is reached, return -1
            if self.found_eof:
                return -1
            # Refill the buffer
            self.refill()
        
        # Return the next byte from the buffer
        return self.buffer[self.pos_read] if self.pos_read < self.buffer_pos else -1

    # Get the number of bytes available to read from the input stream
    def available(self):
        # Get the number of bytes available from the input stream
        available = self.input.readable()
        # If the buffer needs to be refilled, return the number of bytes available from the input stream
        if self.needs_refill():
            return available
        # Otherwise, return the number of bytes remaining in the buffer and the number of bytes available from the input stream
        return self.buffer_pos - self.pos_read + available

    # Read a block of bytes from the input stream into a byte array
    def read_block(self):
        # Save the current buffer position and number of bytes read
        self.push_refresh_data()
        # Create a new byte array with the same size as the buffer
        cloned = bytearray(self.buffer_size)
        # Copy the contents of the buffer into the new byte array, if there are any
        if self.buffer_pos > 0:
            cloned[:self.buffer_pos] = self.buffer[:self.buffer_pos]
        # Refill the buffer
        self.refill()
        # Return the cloned byte array
        return cloned

    # Check if the buffer needs to be refilled
    def needs_refill(self):
        # Return true if the number of bytes read from the buffer is equal to the number of bytes in the buffer
        return self.pos_read == self.buffer_pos

    # Refill the buffer with new data from the input stream
    def refill(self):
        # Reset the buffer position and number of bytes read
        self.pos_read = 0
        self.buffer_pos = 0
        # Read bytes from the input stream into the buffer until it is full or the end of the stream is reached
        while self.buffer_pos < self.buffer_size:
            read = self.input.read(1)
            if not read:
                # If the end of the stream is reached, set the found_eof flag and break the loop
                self.found_eof = True
                break
            # Store the read byte in the buffer
            self.buffer[self.buffer_pos] = read[0]
            self.buffer_pos += 1

    # Save the current buffer position and number of bytes read, and refill the buffer
    def push_refresh_data(self):
        # Calculate the number of bytes read from the buffer
        length = self.buffer_pos - self.pos_read
        # Copy the contents of the buffer from the current position to the beginning of the buffer
        self.buffer[:length] = self.buffer[self.pos_read:self.buffer_pos]
        # Reset the buffer position and number of bytes read
        self.buffer_pos = length
        self.pos_read = 0
        # Refill the buffer
        self.refill()

    # Close the input stream
    def close(self):
        # Close the input stream, if it is not null
        if self.input is not None:
            try:
                self.input.close()
            finally:
                # Set the input stream to None
                self.input = None

# Main method to test the implementation
if __name__ == "__main__":
    import sys

    try:
        # Read the buffer size from the standard input
        buffer_size = int(input())
        # Read a line from the standard input and convert it to a byte array
        input_string = input()
        input_bytes = input_string.encode()
        # Create a new instance of the Main class with the byte array input and the specified buffer size
        buffered_reader = Main(input_bytes, buffer_size)
        # Read bytes from the input stream and print them to the standard output until the end of the stream is reached
        read_byte = buffered_reader.read()
        while read_byte != -1:
            print(chr(read_byte), end='')
            read_byte = buffered_reader.read()
        # Close the input stream
        buffered_reader.close()
    except IOError as e:
        # Print an error message if an error occurs
        print(f"An error occurred: {e}", file=sys.stderr)

# <END-OF-CODE>
