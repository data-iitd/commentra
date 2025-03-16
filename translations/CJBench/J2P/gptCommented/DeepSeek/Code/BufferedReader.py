import io
import sys

class CustomInputStream:
    DEFAULT_BUFFER_SIZE = 5

    def __init__(self, input_bytes, buffer_size=DEFAULT_BUFFER_SIZE):
        self.buffer_size = buffer_size
        self.buffer = bytearray(input_bytes)
        self.pos_read = 0
        self.buffer_pos = 0
        self.found_eof = False

    def read(self):
        if self.needs_refill():
            if self.found_eof:
                return -1
            self.refill()
        return self.buffer[self.pos_read] if self.pos_read < self.buffer_pos else -1

    def available(self):
        if self.needs_refill():
            return len(self.buffer) - self.pos_read
        return self.buffer_pos - self.pos_read + len(self.buffer)

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
            if not self.buffer:
                self.found_eof = True
                break
            self.buffer.append(sys.stdin.read(1))
            self.buffer_pos += 1

    def push_refresh_data(self):
        length = self.buffer_pos - self.pos_read
        self.buffer[:length] = self.buffer[self.pos_read:self.buffer_pos]
        self.buffer_pos = length
        self.pos_read = 0
        self.refill()

    def close(self):
        pass

def main():
    buffer_size = int(sys.stdin.readline().strip())
    input_string = sys.stdin.readline().strip()
    buffered_reader = CustomInputStream(input_string.encode(), buffer_size)
    read_byte = buffered_reader.read()
    while read_byte != -1:
        print(chr(read_byte), end='')
        read_byte = buffered_reader.read()
    buffered_reader.close()

if __name__ == "__main__":
    main()
