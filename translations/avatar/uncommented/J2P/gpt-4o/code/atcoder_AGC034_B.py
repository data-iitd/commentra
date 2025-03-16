import sys

class BABC:
    def solve(self, test_number, input_stream, output_stream):
        s = input_stream.readline().strip().replace("BC", "D")
        cnt = 0
        tmp = 0
        for char in s:
            if char == 'A':
                tmp += 1
            elif char == 'D':
                cnt += tmp
            else:
                tmp = 0
        output_stream.write(f"{cnt}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = BABC()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
