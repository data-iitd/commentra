import sys

class FastReader:
    # FastReader class declaration

    def __init__(self):
        # Constructor declaration
        self.input = sys.stdin.read  # Using sys.stdin.read for fast input
        self.data = self.input().split()  # Reading all input at once and splitting into tokens
        self.index = 0  # Initializing index for reading tokens

    def next(self):
        # Method for reading the next token from the input
        token = self.data[self.index]  # Getting the current token
        self.index += 1  # Moving to the next token
        return token  # Returning the current token

    def next_int(self):
        # Method for reading the next integer from the input
        return int(self.next())  # Converting the next token to an integer and returning it

def main():
    # Main function declaration
    in_reader = FastReader()  # Creating an instance of FastReader class for reading input

    n = in_reader.next_int()  # Reading the number of rows in the grid
    m = in_reader.next_int()  # Reading the number of banned cells

    banned_rows = set()  # Creating a Set to store banned rows
    banned_cols = set()  # Creating a Set to store banned columns

    for _ in range(m):
        # Reading banned cells and adding them to the respective Sets
        r = in_reader.next_int()
        if 1 < r < n:
            banned_rows.add(r)  # Adding banned row if it's within bounds

        c = in_reader.next_int()
        if 1 < c < n:
            banned_cols.add(c)  # Adding banned column if it's within bounds

    answer = (n - 2) * 2  # Initializing answer as the total number of cells in the grid minus the banned cells
    answer -= len(banned_rows)  # Subtracting the number of banned rows
    answer -= len(banned_cols)  # Subtracting the number of banned columns

    if n % 2 != 0:
        # Special case when the number of rows is odd
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            # If the middle cell is not banned, decrement the answer
            answer -= 1

    print(answer)  # Writing the answer to the output stream

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
