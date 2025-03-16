class BufferedReader:
    def __init__(self, input_stream, buffer_size=5):
        self.input_stream = input_stream
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
        return self.buffer[self.pos_read] if self.pos_read < self.buffer_pos else -1

    def available(self):
        return self.input_stream.peek(1) if self.needs_refill() else self.buffer_pos - self.pos_read + self.input_stream.peek(1)

    def read_block(self):
        self.push_refresh_data()
        cloned = bytearray(self.buffer_size)
        if self.buffer_pos > 0:
            cloned[:self.buffer_pos] = self.buffer[:self.buffer_pos]
        self.refill()
        return bytes(cloned)

    def needs_refill(self):
        return self.pos_read == self.buffer_pos

    def refill(self):
        self.pos_read = 0
        self.buffer_pos = 0
        while self.buffer_pos < self.buffer_size:
            read = self.input_stream.read(1)
            if read == -1:
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
        self.input_stream.close()


# Example usage:
# input_stream = io.BytesIO(b"Hello, World!")
# buffered_reader = BufferedReader(input_stream, buffer_size=5)
# while True:
#     byte_read = buffered_reader.read()
#     if byte_read == -1:
#         break
#     print(chr(byte_read), end="")
# buffered_reader.close()

