import sys

class Main:
    def __init__(self):
        self.out = sys.stdout
        self.out.flush()

    def main(self):
        n = int(input().strip())
        k = int(input().strip())
        bb = list(map(int, input().strip().split()))
        aa = []
        m = 0
        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if len(aa) <= j or aa[j] >= a + k:
                    bb[a] -= 1
                else:
                    j += 1
            aa.insert(j, a)
        for i in range(n):
            print(aa[i] + 1, end=' ')
        print()

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
