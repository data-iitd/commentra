import sys

class Main:

    def __init__(self):
        self.br = None
        self.st = None
        self.out = None

    def run(self):
        self.br = sys.stdin
        self.out = sys.stdout
        self.solve()
        self.br.close()
        self.out.close()

    def solve(self):
        x = int(self.next())
        t = int(self.next())
        a = int(self.next())
        b = int(self.next())
        da = int(self.next())
        db = int(self.next())

        first = 0
        second = 0
        ok = False

        for i in range(t):
            first = a - (da * i)
            for j in range(t):
                second = b - (db * j)

                if second + first == x or second == x or first == x or x == 0:
                    ok = True
                    break
            if ok:
                break

        if ok:
            self.out.write("YES")
        else:
            self.out.write("NO")

    def next(self):
        if self.st is None or not self.st.hasMoreTokens():
            try:
                self.st = StringTokenizer(self.br.readLine())
            except:
                return "END_OF_FILE"
        return self.st.nextToken()

    def nextInt(self):
        return int(self.next())

if __name__ == "__main__":
    Main().run()

