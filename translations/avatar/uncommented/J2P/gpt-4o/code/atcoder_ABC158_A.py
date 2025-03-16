import sys

class AStationAndBus:
    def solve(self, test_number, input_stream, output_stream):
        s = input_stream.readline().strip()
        if 'A' in s and 'B' in s:
            output_stream.write("Yes\n")
        else:
            output_stream.write("No\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = AStationAndBus()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
