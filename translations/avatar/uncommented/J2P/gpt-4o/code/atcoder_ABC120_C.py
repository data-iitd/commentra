import sys

class TaskB:
    def solve(self, test_number, input_stream, output_stream):
        x = input_stream.readline().strip()
        stack = []
        c = 0
        
        for char in x:
            stack.append(char)
            while len(stack) > 1:
                p = stack.pop()
                q = stack.pop()
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    c += 1
                    continue
                else:
                    stack.append(q)
                    stack.append(p)
                    break
        
        output_stream.write(f"{c * 2}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = TaskB()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
