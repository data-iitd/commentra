import sys

class Main:
    
    # Method to calculate the XOR operation on a given string with a specific character
    def cal(self, s, c):
        n = len(s)  # Getting the length of the given string
        m = n - 1   # Initializing a variable 'm' to keep track of the index of the previous character
        ans = 0     # Initializing a variable 'ans' to store the result of XOR operation
        
        for i in range(n):  # Looping through each character in the given string
            if s[i] == c and (m & i) == i:  # Checking if the current character is the given character and the difference between its index and the index of the previous character is a power of 2
                ans ^= 1  # If yes, performing XOR operation on 'ans'
        
        return ans  # Returning the result of XOR operation
    
    # Method to read input and process it
    def solve(self):
        n = int(input())  # Reading the number of test cases
        
        for testCase in range(1, n + 1):  # Looping through each test case
            num = int(input())  # Reading the length of the given string
            s = input()         # Reading the given string
            
            differences = []  # List to store the differences between adjacent characters
            
            for i in range(1, num):  # Looping through each character except the first one in the given string
                differences.append(abs(ord(s[i]) - ord(s[i - 1])))  # Appending the absolute difference between adjacent characters
            
            if num == 2:  # Checking if the given string has only two characters
                print(differences[0])  # If yes, printing the first character of the string
                continue  # And moving to the next test case
            
            s = ''.join(map(str, differences))  # Converting the list of differences to a string
            
            if '1' in s:  # Checking if the given string contains the character '1'
                print(self.cal(s, '1'))  # If yes, printing the result of XOR operation on the given string with character '1'
            else:
                print(self.cal(s, '2') * 2)  # If no, performing XOR operation on the given string with character '2' and multiplying the result by 2

# Main execution
if __name__ == "__main__":
    Main().solve()

# <END-OF-CODE>
