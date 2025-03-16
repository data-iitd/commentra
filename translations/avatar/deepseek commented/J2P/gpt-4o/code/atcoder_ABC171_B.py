import sys

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = []

    def n(self):
        while not self.tokenizer:
            self.tokenizer = self.reader.readline().split()
        return self.tokenizer.pop(0)

    def ni(self):
        return int(self.n())

class Solution:
    def solve(self, in_reader, out_writer):
        n = in_reader.ni()  # Reads the number of elements (n)
        k = in_reader.ni()  # Reads the number of elements to consider (k)
        a = [in_reader.ni() for _ in range(n)]  # Reads the elements into a list
        a.sort()  # Sorts the list
        ans = sum(a[i] for i in range(k))  # Sums the first k elements
        out_writer.write(f"{ans}\n")  # Prints the result

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = output_stream
    sol = Solution()
    sol.solve(in_reader, out_writer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
