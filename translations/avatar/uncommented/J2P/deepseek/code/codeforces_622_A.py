import sys
import io

BUFFERSIZE = 512000

def input_reader():
    return io.BytesIO(sys.stdin.read()).readline

def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)

def solve():
    position = int(input_reader().decode().strip())
    nrstSeqStartIndx = 1
    while get_value_at_index(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2
    while get_value_at_index(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1
    start_index = get_value_at_index(nrstSeqStartIndx)
    print((position - start_index) + 1)

def main():
    solve()

if __name__ == "__main__":
    main()
