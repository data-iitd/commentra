import sys

class TaskD:
    def solve(self, test_number, input_stream, output_stream):
        S = input_stream.readline().strip()
        score = 0
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]
            if my != his:
                score += 1 if my == 'p' else -1
        output_stream.write(f"{score}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = TaskD()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
