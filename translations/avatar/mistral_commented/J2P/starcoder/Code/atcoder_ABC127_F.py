
import sys
import heapq

class Main:
    def __init__(self):
        self.outputStream = sys.stdout
        self.out = sys.stdout

    def main(self):
        br = sys.stdin
        t = int(br.readline())

        s = br.readline().split()

        pqmax = []
        pqmin = []
        sumMin = 0
        sumMax = 0
        sumb = 0
        min = 0

        while t > 0:
            if s[0].charAt(0) == '2':
                ans = min
                ans *= len(pqmin)
                ans -= sumMin
                ans1 = min
                ans1 = sumMax - ans1
                self.out.write(str(min) + " " + str(ans + ans1 + sumb) + "\n")
            else:
                in = int(s[1])
                sumb += long(s[2])

                if in > min:
                    heapq.heappush(pqmax, in)
                    sumMax += in
                else:
                    heapq.heappush(pqmin, in)
                    sumMin += in

                if len(pqmin) > len(pqmax):
                    sumMax += heapq.heappop(pqmin)
                    sumMin -= heapq.heappop(pqmin)
                    heapq.heappush(pqmax, heapq.heappop(pqmin))
                elif len(pqmin) < len(pqmax):
                    sumMax -= heapq.heappop(pqmax)
                    sumMin += heapq.heappop(pqmax)
                    heapq.heappush(pqmin, heapq.heappop(pqmax))

                min = pqmin[0]

            s = br.readline().split()
            t -= 1

        self.out.close()

if __name__ == "__main__":
    obj = Main()
    obj.main()

