import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin  # Using standard input

    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = aa[i].upper()  # Converting the characters to uppercase
            b = bb[j].upper()

            if a != b:  # If characters are not equal, return the difference
                return ord(a) - ord(b)

            i += 1  # Incrementing the index i in aa
            j += 1  # Incrementing the index j in bb
            m -= 1

        return 0  # If all characters match, return 0

    def main(self):
        n = int(self.sc.readline().strip())  # Reading the number of character arrays
        ss = [self.sc.readline().strip() for _ in range(n)]  # Reading character arrays

        cc = list(self.sc.readline().strip())  # Reading the character array to be compared
        m = len(cc)  # Finding the length of the character array cc

        c = self.sc.readline().strip()  # Reading the character to be matched
        c_ = c.upper()  # Converting the character to uppercase
        a = 'b' if c == 'a' else 'a'  # Determining the character a based on c
        a_ = a.upper()  # Converting the character a to uppercase

        lucky = [False] * m  # Creating a boolean array to keep track of matching indices

        # Iterating through each character in cc and comparing it with all character arrays in ss
        for j in range(m):
            for i in range(n):
                l = len(ss[i])  # Finding the length of the character array in ss at index i

                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):  # Setting the boolean value in lucky to true
                        lucky[j + h] = True

        # Updating cc based on the boolean values in lucky
        for j in range(m):
            if lucky[j]:  # If the boolean value at index j in lucky is true
                if cc[j].lower() == c:  # If the character at index j in cc is equal to c in lowercase
                    cc[j] = a_ if cc[j].isupper() else a  # Update based on character a
                else:
                    cc[j] = c_ if cc[j].isupper() else c  # Update based on character c

        # Printing the updated character array cc
        print(''.join(cc))

if __name__ == "__main__":
    Main().main()  # Creating an instance of Main class and calling the main method

# <END-OF-CODE>
