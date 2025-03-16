class Main:  # Defining the Main class
    MOD = 1000000007  # Defining a constant value for modulo arithmetic
    MAX = float('inf')  # Defining a constant value for maximum integer
    LMAX = float('inf')  # Defining a constant value for maximum long
    len = int(1e6) + 1  # Defining the length of an array

    def do_it(self):  # Defining the method do_it() to contain the logic of the program
        N = int(input())  # Reading the number of elements in the array
        K = int(input())  # Reading the long value K
        A = [int(input()) - 1 for _ in range(N)]  # Creating an integer array A of size N

        used = set()  # Creating a set named used to store the indices that have already been processed
        idx = [0] * N  # Creating an integer array named idx to store the position of the current index in the circular array
        pos = [0] * N  # Creating an integer array named pos to store the position of the previous index in the circular array
        next_index = 0  # Initializing the variable next_index
        cur = 0  # Initializing the variable cur

        # Finding the cycle starting point using BFS
        while next_index not in used:
            used.add(next_index)  # Adding the current index to the set used
            idx[next_index] = cur  # Storing the current position in the idx array
            pos[cur] = next_index  # Storing the previous position in the pos array
            next_index = A[next_index]  # Moving to the next index
            cur += 1  # Incrementing the current position

        a = cur - idx[next_index]  # Calculating the length of the cycle
        b = idx[next_index]  # Calculating the starting position of the cycle in the array
        ans = (10000 * a + K - b + self.MOD) % a + b  # Calculating the answer using the formula

        # Checking if the starting position of the cycle is greater than K, if yes then the answer is K
        if b > K:
            ans = K

        print(pos[ans] + 1)  # Printing the position of the answer in the array

if __name__ == "__main__":  # Defining the main method to start the execution of the program
    Main().do_it()  # Calling the do_it() method to execute the logic of the program

# <END-OF-CODE>
