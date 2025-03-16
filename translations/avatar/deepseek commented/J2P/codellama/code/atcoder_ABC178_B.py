
# FastReader class to read input efficiently
class FastReader:
    def __init__(self):
        self.br = open(0)
        self.st = None

    def next(self):
        while self.st == None or not self.st.hasMoreElements():
            try:
                self.st = StringTokenizer(self.br.readline())
            except:
                self.st = None
        return self.st.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        str = ""
        try:
            str = self.br.readline()
        except:
            pass
        return str

# Function to calculate x^y mod mod using efficient exponentiation by squaring
def modPower(x, y, mod):
    res = 1
    x %= mod
    if x == 0:
        return 0
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % mod
        y = y >> 1
        x = (x * x) % mod
    return res

# Generic pair class to hold two elements of type T1 and T2
class pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Main function to read input, calculate the maximum product, and print the result
if __name__ == "__main__":
    in = FastReader()
    a = [0] * 4
    for i in range(4):
        a[i] = in.nextLong()
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

# END-OF-CODE
