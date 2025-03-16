import io
import sys

class BufferedInputStream:
    DEFAULT_BUFFER_SIZE = 5

    def __init__(self, input_stream, buffer_size=DEFAULT_BUFFER_SIZE):
        self.buffer_size = buffer_size
        self.buffer = bytearray(buffer_size)
        self.pos_read = 0
        self.buffer_pos = 0
        self.found_eof = False
        self.input_stream = input_stream

    def read(self):
        if self.needs_refill():
            if self.found_eof:
                return -1
            self.refill()
        return self.buffer[self.pos_read] if self.pos_read < self.buffer_pos else -1

    def available(self):
        if self.needs_refill():
            return self.input_stream.in_waiting
        return self.buffer_pos - self.pos_read + self.input_stream.in_waiting

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
            read = self.input_stream.read(1)
            if read == b"":
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
        if self.input_stream:
            self.input_stream.close()
            self.input_stream = None

def main():
    print("Enter buffer size:")
    buffer_size = int(sys.stdin.readline().strip())
    print("Enter input string:")
    input_string = sys.stdin.readline().strip()
    buffered_reader = BufferedInputStream(io.BytesIO(input_string.encode()), buffer_size)
    print("Reading byte-by-byte:")
    while True:
        read_byte = buffered_reader.read()
        if read_byte == -1:
            break
        print(chr(read_byte), end="")
    buffered_reader.close()

if __name__ == "__main__":
    main()
