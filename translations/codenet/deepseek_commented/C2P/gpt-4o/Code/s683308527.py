# Include necessary imports
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of lines
    for _ in range(n):  # Loop through each line
        s = sys.stdin.readline()  # Read the input line
        c = s.find("Hoshino")  # Find the index of "Hoshino"
        while c != -1:  # While "Hoshino" is found
            s = s[:c] + "Hoshina" + s[c + 7:]  # Replace "Hoshino" with "Hoshina"
            c = s.find("Hoshino", c + 1)  # Find the next occurrence
        print(s, end='')  # Print the modified line

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
