import sys

class CColoringColorfully:
    def solve(self, test_number, input_stream, output_stream):
        x = input_stream.readline().strip()
        a = list(x)
        b = list(x)
        a1 = 0
        a2 = 0
        
        for i in range(1, len(x)):
            if a[i] == a[i - 1]:
                a[i] = '0' if a[i] == '1' else '1'
                a1 += 1
        
        for i in range(len(x) - 1, 0, -1):
            if b[i] == b[i - 1]:
                b[i - 1] = '0' if b[i - 1] == '1' else '1'
                a2 += 1
        
        output_stream.write(f"{min(a1, a2)}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = CColoringColorfully()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
