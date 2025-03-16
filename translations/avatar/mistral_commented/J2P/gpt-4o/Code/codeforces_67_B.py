import sys  # Importing required module for input and output

class Main:
    def __init__(self):
        self.sc = sys.stdin  # Creating a standard input stream

    def main(self):
        n = int(self.sc.readline().strip())  # Reading the number of elements in the array 'bb'
        k = int(self.sc.readline().strip())  # Reading the value of 'k'
        bb = list(map(int, self.sc.readline().strip().split()))  # Reading the array 'bb'

        aa = [0] * n  # Creating an integer array 'aa' of size 'n'
        m = 0  # Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

        for a in range(n - 1, -1, -1):  # Iterating through the array 'bb' from the last index to the first index
            j = 0
            while bb[a] > 0:  # While there are still elements in 'bb' at index 'a' to be processed
                if j >= m or aa[j] >= a + k:  # Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
                    bb[a] -= 1  # If true, decrement the number of elements in 'bb' at index 'a'
                j += 1

            # Shifting elements in 'aa' to make space for the new element
            for j_ in range(m, j, -1):  # Iterating through the array 'aa' from the last index added to the current index 'j'
                aa[j_] = aa[j_ - 1]  # Swapping the elements at indices 'j_' and 'j_ - 1'

            aa[j] = a  # Adding the current index 'a' to the array 'aa' at index 'j'
            m += 1  # Incrementing the count of elements in 'aa'

        # Printing the elements of 'aa' with 1-based indexing
        print(" ".join(str(aa[i] + 1) for i in range(n)))  # Printing each element of 'aa' to the console

if __name__ == "__main__":
    o = Main()  # Creating an instance of the Main class
    o.main()  # Calling the main method of the Main class

# <END-OF-CODE>
