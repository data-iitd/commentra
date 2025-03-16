
import sys

def main():
    inputStream = sys.stdin
    outputStream = sys.stdout
    in = inputStream.readline()
    out = outputStream.write
    solver = AStationAndBus()
    solver.solve(1, in, out)

class AStationAndBus:
    def solve(self, testNumber, in, out):
        s = in.strip()
        if "A" in s and "B" in s:
            out.write("Yes\n")
        else:
            out.write("No\n")

if __name__ == "__main__":
    main()

