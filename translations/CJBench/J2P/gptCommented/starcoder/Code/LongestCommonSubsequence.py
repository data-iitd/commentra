import sys

# Class to store the LCS of two strings
class LCS:
    # Constructor to initialize the LCS
    def __init__(self, str1, str2):
        # Check for null input strings
        if str1 == None or str2 == None:
            raise ValueError("Input strings cannot be null")

        # Check for empty input strings
        if len(str1) == 0 or len(str2) == 0:
            raise ValueError("Input strings cannot be empty")

        # Split the strings into character arrays
        self.arr1 = str1.split("")
        self.arr2 = str2.split("")

        # Create a matrix to store lengths of longest common subsequence
        self.lcsMatrix = [[0 for i in range(len(self.arr2) + 1)] for j in range(len(self.arr1) + 1)]

        # Initialize the first column of the matrix to 0
        for i in range(len(self.arr1) + 1):
            self.lcsMatrix[i][0] = 0

        # Initialize the first row of the matrix to 0
        for j in range(len(self.arr2) + 1):
            self.lcsMatrix[0][j] = 0

        # Fill the LCS matrix using dynamic programming
        for i in range(1, len(self.arr1) + 1):
            for j in range(1, len(self.arr2) + 1):
                # If characters match, increment the value from the diagonal cell
                if self.arr1[i - 1] == self.arr2[j - 1]:
                    self.lcsMatrix[i][j] = self.lcsMatrix[i - 1][j - 1] + 1
                else:
                    # Otherwise, take the maximum value from the left or above cell
                    self.lcsMatrix[i][j] = max(self.lcsMatrix[i - 1][j], self.lcsMatrix[i][j - 1])

    # Method to construct the LCS string from the LCS matrix
    def getLCS(self):
        # Create a string builder to store the LCS
        lcs = ""

        # Backtrack through the matrix to find the LCS characters
        i = len(self.arr1)
        j = len(self.arr2)
        while i > 0 and j > 0:
            # If characters match, add to the LCS and move diagonally
            if self.arr1[i - 1] == self.arr2[j - 1]:
                lcs = self.arr1[i - 1] + lcs
                i -= 1
                j -= 1
            else:
                # Move up if the value above is greater
                if self.lcsMatrix[i - 1][j] > self.lcsMatrix[i][j - 1]:
                    i -= 1
                else:
                    # Move left if the value to the left is greater
                    j -= 1

        # Return the LCS
        return lcs

# Main method to execute the program
def main():
    # Check for command line arguments
    if len(sys.argv)!= 3:
        raise ValueError("Please provide two input strings")

    # Create an object to store the LCS of the two strings
    lcs = LCS(sys.argv[1], sys.argv[2])

    # Output the result
    print("The Longest Common Subsequence is: " + lcs.getLCS())

# Entry point of the program
if __name__ == "__main__":
    main()

# 