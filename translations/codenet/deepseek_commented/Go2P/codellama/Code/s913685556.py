
# Main function: Initializes a new Scanner, reads two integers A and B,
# and calculates the maximum value among A+B, A-B, and A*B. Finally, it prints the maximum value.
def main():
    sc = Scanner()
    A, B = sc.nextInt(), sc.nextInt()

    mx = max(A+B, A-B)
    mx = max(mx, A*B)
    print(mx)

# Scanner type: Wraps a bufio.Reader and provides methods to read various types of input data.
class Scanner:
    def __init__(self):
        self.r = bufio.Reader()
        self.buf = []
        self.p = 0

    # Next method: Reads the next token from the input buffer.
    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = string(self.buf[start:self.p])
        self.p++
        return result

    # NextLine method: Reads the next line from the input buffer.
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return string(self.buf[start:])

    # NextInt method: Reads the next integer from the input buffer.
    def nextInt(self):
        v, _ = strconv.Atoi(self.next())
        return v

    # NextInt64 method: Reads the next 64-bit integer from the input buffer.
    def nextInt64(self):
        v, _ = strconv.ParseInt(self.next(), 10, 64)
        return v

    # NextFloat method: Reads the next floating-point number from the input buffer.
    def nextFloat(self):
        v, _ = strconv.ParseFloat(self.next(), 64)
        return v

    # NextIntArray method: Reads the next array of integers from the input buffer.
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(string(self.buf[start:self.p]), 10, 0)
                result.append(int(v))
                start = self.p + 1
        return result

    # NextInt64Array method: Reads the next array of 64-bit integers from the input buffer.
    def nextInt64Array(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(string(self.buf[start:self.p]), 10, 64)
                result.append(v)
                start = self.p + 1
        return result

    # NextMap method: Reads the next map of integers from the input buffer.
    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                v, _ = strconv.Atoi(string(self.buf[start:self.p]))
                mp[v] = True
                start = self.p + 1
        v, _ = strconv.Atoi(string(self.buf[start:self.p]))
        mp[v] = True

        return mp

    # pre method: Ensures that the buffer is preprocessed before reading.
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # readLine method: Reads the next line from the input buffer.
    def readLine(self):
        self.buf = []
        for {
            l, p, e = self.r.ReadLine()
            if e != nil:
                panic(e)
            self.buf = append(self.buf, l...)
            if not p:
                break
        }

# max function: Returns the larger of two integers.
def max(a, b):
    if a < b:
        return b
    return a

# END-OF-CODE
