import io

class BufferedReader:
    DEFAULT_BUFFER_SIZE = 5

    def __init__(self, input_data, buffer_size):
        if isinstance(input_data, bytes):
            self.input = io.BytesIO(input_data)
        else:
            self.input = input_data

        if self.input.read(1) == b'':
            raise IOError("Empty or already closed stream provided")
        self.input.seek(0)

        self.buffer_size = buffer_size
        self.buffer = bytearray(buffer_size)
        self.pos_read = 0
        self.buffer_pos = 0
        self.found_eof = False

    def read(self):
        if self.needs_refill():
            if self.found_eof:
                return -1
            self.refill()
        if self.pos_read < self.buffer_pos:
            byte = self.buffer[self.pos_read]
            self.pos_read += 1
            return byte
        return -1

    def available(self):
        available = self.input.read(0)
        if self.needs_refill():
            return len(available)
        return self.buffer_pos - self.pos_read + len(available)

    def read_block(self):
        self.push_refresh_data()
        cloned = bytearray(self.buffer_size)

        if self.buffer_pos > 0:
            cloned[:self.buffer_pos] = self.buffer[:self.buffer_pos]

        self.refill()
        return cloned

    def needs_refill(self):
        return self.pos_read == self.buffer_pos

    def refill(self):
        self.pos_read = 0
        self.buffer_pos = 0
        while self.buffer_pos < self.buffer_size:
            read = self.input.read(1)
            if read == b'':
                self.found_eof = True
                break
            self.buffer[self.buffer_pos] = read[0]
            self.buffer_pos += 1

    def push_refresh_data(self):
        length = self.buffer_pos - self.pos_read
        self.buffer[:length] = self.buffer[self.pos_read:self.buffer_pos]
        self.buffer_pos = length
        self.pos_read = 0
        self.refill()

    def close(self):
        if self.input:
            self.input.close()
            self.input = None

if __name__ == "__main__":
    try:
        buffer_size = int(input("Enter buffer size: "))
        input_string = input("Enter input string: ")

        buffered_reader = BufferedReader(input_string.encode(), buffer_size)
        print("Reading byte-by-byte:")

        while True:
            read_byte = buffered_reader.read()
            if read_byte == -1:
                break
            print(chr(read_byte), end='')

        buffered_reader.close()
    except IOError as e:
        print(f"An error occurred: {e}")

# <END-OF-CODE>
