

import bufio
import os
import sys

# Package main defines the entry point for the program.

# Custom Sorting Types
class pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

class pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.index < other.index

    def __gt__(self, other):
        return self.index > other.index

    def __eq__(self, other):
        return self.index == other.index

    def __le__(self, other):
        return self.index <= other.index

    def __ge__(self, other):
        return self.index >= other.index

# Constants and Variables
INF = 1e8
scanner = bufio.Scanner(os.stdin.buffer, initial_buffer_size=1e4, max_buffer_size=1e8)
scanner.buffer = bufio.BufferedRead(sys.stdin.buffer, max_buffer_size=1e8)
scanner.buffer.read = lambda size: scanner.buffer.read(size)
scanner.buffer.read1 = lambda size: scanner.buffer.read1(size)
scanner.buffer.readinto = lambda b: scanner.buffer.readinto(b)
scanner.buffer.readline = lambda: scanner.buffer.readline()
scanner.buffer.readlines = lambda sizehint: scanner.buffer.readlines(sizehint)
scanner.buffer.tell = lambda: scanner.buffer.tell()
scanner.buffer.seek = lambda offset, whence: scanner.buffer.seek(offset, whence)
scanner.buffer.truncate = lambda size: scanner.buffer.truncate(size)
scanner.buffer.write = lambda b: scanner.buffer.write(b)
scanner.buffer. writelines = lambda lines: scanner.buffer.writelines(lines)
scanner.buffer.raw = scanner.buffer.raw
scanner.buffer.detach = lambda: scanner.buffer.detach()
scanner.buffer.close = lambda: scanner.buffer.close()
scanner.buffer.fileno = lambda: scanner.buffer.fileno()
scanner.buffer.isatty = lambda: scanner.buffer.isatty()
scanner.buffer.readable = lambda: scanner.buffer.readable()
scanner.buffer.seekable = lambda: scanner.buffer.seekable()
scanner.buffer.writable = lambda: scanner.buffer.writable()
scanner.buffer.writeable = lambda: scanner.buffer.writeable()
scanner.buffer.closed = lambda: scanner.buffer.closed()
scanner.buffer.softspace = lambda: scanner.buffer.softspace()
scanner.buffer.encoding = lambda: scanner.buffer.encoding()
scanner.buffer.errors = lambda: scanner.buffer.errors()
scanner.buffer.newlines = lambda: scanner.buffer.newlines()
scanner.buffer.line_buffering = lambda: scanner.buffer.line_buffering()
scanner.buffer.name = lambda: scanner.buffer.name()
scanner.buffer.mode = lambda: scanner.buffer.mode()
scanner.buffer.detach = lambda: scanner.buffer.detach()
scanner.buffer.read_chunk_size = lambda: scanner.buffer.read_chunk_size()
scanner.buffer.write_chunk_size = lambda: scanner.buffer.write_chunk_size()
scanner.buffer.read_chunk_limit = lambda: scanner.buffer.read_chunk_limit()
scanner.buffer.write_chunk_limit = lambda: scanner.buffer.write_chunk_limit()
scanner.buffer.read_chunk_buffer = lambda: scanner.buffer.read_chunk_buffer()
scanner.buffer.write_chunk_buffer = lambda: scanner.buffer.write_chunk_buffer()
scanner.buffer.read_chunk_buffer_size = lambda: scanner.buffer.read_chunk_buffer_size()
scanner.buffer.write_chunk_buffer_size = lambda: scanner.buffer.write_chunk_buffer_size()
scanner.buffer.read_chunk_buffer_limit = lambda: scanner.buffer.read_chunk_buffer_limit()
scanner.buffer.write_chunk_buffer_limit = lambda: scanner.buffer.write_chunk_buffer_limit()
scanner.buffer.read_chunk_buffer_full = lambda: scanner.buffer.read_chunk_buffer_full()
scanner.buffer.write_chunk_buffer_full = lambda: scanner.buffer.write_chunk_buffer_full()
scanner.buffer.read_chunk_buffer_empty = lambda: scanner.buffer.read_chunk_buffer_empty()
scanner.buffer.write_chunk_buffer_empty = lambda: scanner.buffer.write_chunk_buffer_empty()
scanner.buffer.read_chunk_buffer_clear = lambda: scanner.buffer.read_chunk_buffer_clear()
scanner.buffer.write_chunk_buffer_clear = lambda: scanner.buffer.write_chunk_buffer_clear()
scanner.buffer.read_chunk_buffer_fill = lambda: scanner.buffer.read_chunk_buffer_fill()
scanner.buffer.write_chunk_buffer_fill = lambda: scanner.buffer.write_chunk_buffer_fill()
scanner.buffer.read_chunk_buffer_flush = lambda: scanner.buffer.read_chunk_buffer_flush()
scanner.buffer.write_chunk_buffer_flush = lambda: scanner.buffer.write_chunk_buffer_flush()
scanner.buffer.read_chunk_buffer_available = lambda: scanner.buffer.read_chunk_buffer_available()
scanner.buffer.write_chunk_buffer_available = lambda: scanner.buffer.write_chunk_buffer_available()
scanner.buffer.read_chunk_buffer_available_for_write = lambda: scanner.buffer.read_chunk_buffer_available_for_write()
scanner.buffer.write_chunk_buffer_available_for_write = lambda: scanner.buffer.write_chunk_buffer_available_for_write()
scanner.buffer.read_chunk_buffer_available_for_read = lambda: scanner.buffer.read_chunk_buffer_available_for_read()
scanner.buffer.write_chunk_buffer_available_for_read = lambda: scanner.buffer.write_chunk_buffer_available_for_read()
scanner.buffer.read_chunk_buffer_available_for_read_or_eof = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_eof()
scanner.buffer.write_chunk_buffer_available_for_read_or_eof = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_eof()
scanner.buffer.read_chunk_buffer_available_for_write_or_eof = lambda: scanner.buffer.read_chunk_buffer_available_for_write_or_eof()
scanner.buffer.write_chunk_buffer_available_for_write_or_eof = lambda: scanner.buffer.write_chunk_buffer_available_for_write_or_eof()
scanner.buffer.read_chunk_buffer_available_for_read_or_write = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_write()
scanner.buffer.write_chunk_buffer_available_for_read_or_write = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write()
scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof()
scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof()
scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close()
scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close()
scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel()
scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel()
scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.read_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or_close_or_cancel_or_release = lambda: scanner.buffer.write_chunk_buffer_available_for_read_or_write_or_eof_or