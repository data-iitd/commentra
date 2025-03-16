import io
import sys

class CustomInputStream:
    def __init__(self, input_bytes, buffer_size):
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
        return len(self.buffer) - self.pos_read if not self.needs_refill() else sys.maxsize

    def read_block(self):
        cloned = bytearray(self.buffer)
        self.refill()
        return cloned

    def needs_refill(self):
        return self.pos_read == self.buffer_pos

    def refill(self):
        self.pos_read = 0
        self.buffer_pos = 0
        while self.buffer_pos < self.buffer_size:
            read = sys.stdin.read(1)
            if not read:
                self.found_eof = True
                break
            self.buffer.append(ord(read))
            self.buffer_pos += 1

    def push_refresh_data(self):
        length = self.buffer_pos - self.pos_read
        self.buffer[:] = self.buffer[self.pos_read:]
        self.pos_read = 0
        self.refill()

    def close(self):
        pass

def main():
    buffer_size = int(sys.stdin.readline().strip())
    input_string = sys.stdin.readline().strip()
    buffered_reader = CustomInputStream(bytearray(input_string, 'utf-8'), buffer_size)
    while True:
        read_byte = buffered_reader.read()
        if read_byte == -1:
            break
        print(chr(read_byte), end='')
    buffered_reader.close()

if __name__ == "__main__":
    main()
