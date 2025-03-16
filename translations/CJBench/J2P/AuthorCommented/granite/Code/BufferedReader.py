

import sys

class Main:
    def __init__(self, input, buffer_size):
        self.input = input
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
        return self.pos_read < self.buffer_pos and ord(self.buffer[self.pos_read]) or -1

    def available(self):
        available = self.input.available()
        if self.needs_refill():
            return available
        return self.buffer_pos - self.pos_read + available

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
            if not read:
                self.found_eof = True
                break
            self.buffer[self.buffer_pos] = read
            self.buffer_pos += 1

    def push_refresh_data(self):
        length = self.buffer_pos - self.pos_read
        self.buffer[:length] = self.buffer[self.pos_read:self.buffer_pos]
        self.buffer_pos = length
        self.pos_read = 0
        self.refill()

    def close(self):
        if self.input:
            try:
                self.input.close()
            finally:
                self.input = None

if __name__ == "__main__":
    input_string = input("Enter input string: ")
    buffer_size = int(input("Enter buffer size: "))
    buffered_reader = Main(input_string.encode(), buffer_size)
    print("Reading byte-by-byte:")
    while True:
        read_byte = buffered_reader.read()
        if read_byte == -1:
            break
        print(chr(read_byte), end="")
    buffered_reader.close()

