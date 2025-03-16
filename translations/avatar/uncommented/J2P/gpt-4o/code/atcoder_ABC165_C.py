class Main:
    a = None
    b = None
    c = None
    d = None
    n = 0
    m = 0
    q = 0
    ans = -100

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        
        idx = 0
        Main.n = int(data[idx])
        idx += 1
        Main.m = int(data[idx])
        idx += 1
        Main.q = int(data[idx])
        idx += 1
        
        Main.a = [0] * Main.q
        Main.b = [0] * Main.q
        Main.c = [0] * Main.q
        Main.d = [0] * Main.q
        
        for i in range(Main.q):
            Main.a[i] = int(data[idx]) - 1
            idx += 1
            Main.b[i] = int(data[idx]) - 1
            idx += 1
            Main.c[i] = int(data[idx])
            idx += 1
            Main.d[i] = int(data[idx])
            idx += 1
        
        Main.dfs([])

        print(Main.ans)

    @staticmethod
    def dfs(lst):
        if len(lst) == Main.n:
            score = 0
            for i in range(Main.q):
                if lst[Main.b[i]] - lst[Main.a[i]] == Main.c[i]:
                    score += Main.d[i]
            Main.ans = max(Main.ans, score)
            return
        
        if lst:
            for num in range(lst[-1], Main.m + 1):
                lst.append(num)
                Main.dfs(lst)
                lst.pop()
        else:
            for num in range(1, Main.m + 1):
                lst.append(num)
                Main.dfs(lst)
                lst.pop()

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
