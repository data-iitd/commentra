class Main:  # Defining the Main class

    def run(self):  # Method to run the program
        import sys
        input = sys.stdin.read
        data = input().split()  # Reading all input at once

        index = 0
        N = int(data[index])  # Reading the first integer from the input
        index += 1
        M = int(data[index])  # Reading the second integer from the input
        index += 1

        a = [0] * N  # Creating a list of size N to store integers initialized to 0

        # Reading the queries and updating the list accordingly
        for i in range(M):
            k = int(data[index])  # Reading the number of elements to be updated
            index += 1

            for j in range(k):  # Iterating through the elements to be updated
                s = int(data[index])  # Reading the index of the element to be updated
                index += 1
                s -= 1  # Decreasing the index by 1 as the list index starts from 0

                # Updating the value of the element at the given index
                a[s] |= (1 << i)

        p = 0  # Initializing a variable to store the XOR of all given integers

        # Reading the integers and computing their XOR
        for i in range(M):
            x = int(data[index])  # Reading an integer from the input
            index += 1
            p |= (x << i)  # Computing the XOR of the current integer with the previous result

        ans = 0  # Initializing a variable to store the count of valid answers

        # Iterating through all possible combinations of the list elements
        for s in range(1 << N):  # 1 << N represents 2^N
            t = 0  # Initializing a variable to store the XOR of the current combination with the list elements

            # Computing the XOR of the current combination with the list elements
            for i in range(N):
                if (s >> i) & 1:  # Checking if the i-th bit of the current combination is set
                    t ^= a[i]  # Updating the XOR of the current combination

            # Checking if the XOR of the current combination and the list elements is equal to the given integers
            if p == t:
                ans += 1  # Incrementing the count of valid answers

        print(ans)  # Printing the count of valid answers


if __name__ == "__main__":  # Main entry point of the program
    main = Main()  # Creating an instance of the Main class
    main.run()  # Calling the run method to execute the program

# <END-OF-CODE>
