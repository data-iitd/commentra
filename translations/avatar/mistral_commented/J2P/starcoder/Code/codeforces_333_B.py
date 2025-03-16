
import sys

class Main:
    # Main class declaration

    in = FastReader()
    out = sys.stdout

    def main(self):
        # Main method declaration

        n = self.in.nextInt()
        m = self.in.nextInt()

        bannedRows = set()
        bannedCols = set()

        for i in range(m):
            # Reading banned cells and adding them to the respective Sets

            r = self.in.nextInt()
            if r > 1 and r < n: bannedRows.add(r)

            c = self.in.nextInt()
            if c > 1 and c < n: bannedCols.add(c)

        answer = (n - 2) * 2  # Initializing answer as the total number of cells in the grid minus the banned cells
        answer -= len(bannedRows)  # Subtracting the number of banned rows
        answer -= len(bannedCols)  # Subtracting the number of banned columns

        if n % 2!= 0:
            # Special case when the number of rows is odd

            mid = (n + 1) // 2
            if mid not in bannedRows and mid not in bannedCols:
                # If the middle cell is not banned, decrement the answer
                answer -= 1

        self.out.write(str(answer) + "\n")  # Writing the answer to the output stream
        self.out.close()  # Closing the output stream

    class FastReader:
        # FastReader class declaration

        def __init__(self):
            # Constructor declaration

            self.br = sys.stdin

        def next(self):
            # Method for reading the next token from the input

            return self.br.readline().strip()

        def nextInt(self):
            # Method for reading the next integer from the input

            return int(self.next())

        def nextLong(self):
            # Method for reading the next long integer from the input

            return int(self.next())

        def nextDouble(self):
            # Method for reading the next double from the input

            return float(self.next())

        def nextLine(self):
            # Method for reading the next line from the input

            return str(self.br.readline().strip())

