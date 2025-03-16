# by syu
import sys

class Scanner:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = ""
    
    def read(self):
        self.buffer = self.stream.readline().strip()
    
    def int(self):
        self.read()
        return int(self.buffer)

def Pln(*args):
    print(*args)

def main():
    # Read two integers n and k from standard input
    in_stream = sys.stdin
    scanner = Scanner(in_stream)
    n = scanner.int()
    k = scanner.int()
    
    # Check if n is divisible by k
    if n % k == 0:
        # If n is divisible by k, print 0 to the console
        Pln(0)
    else:
        # If n is not divisible by k, print 1 to the console
        Pln(1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
