
import sys 

class SimpleScanner: 
    def __init__(self, inp): 
        self.inp = inp 
        self.buffer = [] 
        self.eof = False 

    def read(self): 
        if not self.buffer: 
            self.buffer = list(self.inp.read(10240)) 
            if not self.buffer: 
                self.eof = True 
                return '\0' 
        return self.buffer.pop(0) 

    def checkEof(self): 
        if self.eof: 
            raise NoSuchElementException() 

    def nextChar(self): 
        self.checkEof() 
        b = self.read() 
        self.checkEof() 
        return b 

    def next(self): 
        b = self.nextChar() 
        while not self.eof and not b.isspace(): 
            b = self.nextChar() 
        while not self.eof and b.isspace(): 
            b = self.nextChar() 
        return b 

    def nextInt(self): 
        return int(self.next()) 

    def nextLong(self): 
        return long(self.next()) 

    def nextDouble(self): 
        return float(self.next()) 

if __name__ == '__main__': 
    scanner = SimpleScanner(sys.stdin) 
    writer = sys.stdout 

    r = scanner.nextInt() 
    d = scanner.nextInt() 
    x = scanner.nextLong() 

    for i in range(10): 
        x = r * x - d 
        writer.write(str(x) + '\n') 

    writer.close() 

