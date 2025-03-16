import sys

class Main:
    def solve(self):
        x = self.next_int()
        t = self.next_int()
        a = self.next_int()
        b = self.next_int()
        da = self.next_int()
        db = self.next_int()
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
            print("YES")
        else:
            print("NO")

    def run(self):
        self.br = sys.stdin
        self.st = []
        self.solve()

    def next_int(self):
        return int(self.next())

    def next(self):
        while not self.st:
            line = self.br.readline()
            if not line:
                return "END_OF_FILE"
            self.st = line.split()
        return self.st.pop(0)

if __name__ == "__main__":
    Main().run()

# <END-OF-CODE>
