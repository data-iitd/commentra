import sys
from collections import defaultdict

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def next_int(self):
        return int(self.stream.readline().strip())

    def next_ints(self):
        return list(map(int, self.stream.readline().strip().split()))

class Task:
    def solve(self, in_reader, out_writer):
        n = in_reader.next_int()  # Reading the number of elements in the array
        frequency = [0] * 1001  # Creating an array of size 1001 to store the frequency of each element
        
        for _ in range(n):  # Loop to read and store the elements in the array
            index = in_reader.next_int()
            frequency[index] += 1  # Incrementing the frequency of the element at the given index
        
        count_max = max(frequency)  # Finding the maximum frequency
        
        if n % 2 == 0:  # Checking if the number of elements is even
            if count_max <= n // 2:  # If the maximum frequency is less than or equal to half of the number of elements
                out_writer.write("YES\n")  # Printing "YES" as the output
            else:
                out_writer.write("NO\n")  # Else printing "NO" as the output
        else:  # If the number of elements is odd
            if count_max <= n // 2 + 1:  # If the maximum frequency is less than or equal to half of the number of elements plus one
                out_writer.write("YES\n")  # Printing "YES" as the output
            else:
                out_writer.write("NO\n")  # Else printing "NO" as the output

def main():
    in_reader = InputReader(sys.stdin)  # Creating InputReader object for reading input
    out_writer = sys.stdout  # Creating output stream to standard output
    solver = Task()  # Creating Task object to solve the problem
    solver.solve(in_reader, out_writer)  # Calling the solve method of Task object to solve the problem

if __name__ == "__main__":
    main()  # Starting the program

# <END-OF-CODE>
