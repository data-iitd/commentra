
# Import the Scanner class from the java.util package
from java.util import Scanner

# Private constructor to prevent instantiation of the class
class Main:
    def __init__(self):
        pass

    # Method to compute the Longest Common Subsequence (LCS) of two strings
    def getLCS(self, str1, str2):
        # Check for null input strings
        if str1 is None or str2 is None:
            return None
        # Return an empty string if either string is empty
        if len(str1) == 0 or len(str2) == 0:
            return ""

        # Split the strings into character arrays
        arr1 = str1.split("")
        arr2 = str2.split("")

        # Create a matrix to store lengths of longest common subsequence
        lcsMatrix = [[0 for i in range(len(arr2) + 1)] for j in range(len(arr1) + 1)]

        # Initialize the first column of the matrix to 0
        for i in range(len(arr1)):
            lcsMatrix[i][0] = 0

        # Initialize the first row of the matrix to 0
        for j in range(len(arr2)):
            lcsMatrix[0][j] = 0

        # Fill the LCS matrix using dynamic programming
        for i in range(1, len(arr1) + 1):
            for j in range(1, len(arr2) + 1):
                # If characters match, increment the value from the diagonal cell
                if arr1[i - 1] == arr2[j - 1]:
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1
                else:
                    # Otherwise, take the maximum value from the left or above cell
                    lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1])

        # Retrieve the longest common subsequence from the matrix
        return self.lcsString(str1, str2, lcsMatrix)

    # Method to construct the LCS string from the LCS matrix
    def lcsString(self, str1, str2, lcsMatrix):
        lcs = ""
        i = len(str1)
        j = len(str2)

        # Backtrack through the matrix to find the LCS characters
        while i > 0 and j > 0:
            # If characters match, add to the LCS and move diagonally
            if str1[i - 1] == str2[j - 1]:
                lcs += str1[i - 1]
                i -= 1
                j -= 1
            elif lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]:
                # Move up if the value above is greater
                i -= 1
            else:
                # Move left if the value to the left is greater
                j -= 1

        # Reverse the LCS string since we constructed it backwards
        return lcs[::-1]

    # Main method to execute the program
    def main(self):
        # Create a scanner to read input from the user
        scanner = Scanner(System.in)

        # Read two strings from the user
        str1 = scanner.nextLine()
        str2 = scanner.nextLine()

        # Compute the LCS of the two strings
        lcs = self.getLCS(str1, str2)

        # Output the result
        print("The Longest Common Subsequence is: " + lcs)

        # Close the scanner to prevent resource leaks
        scanner.close()

# Create an instance of the Main class and call its main method
Main().main()

