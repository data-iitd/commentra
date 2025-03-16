# Importing the necessary module for reading input
import sys

def main():
    sc_list = []  # Creating an empty list to store the input lines

    # The following loop reads input lines from the console and stores them in the list
    for line in sys.stdin:
        sc_list.append(line.strip())  # Reading the next line from the console and adding it to the list

    # The following line extracts the first line of the input (which contains the number of sheep and wolves)
    numlist = sc_list[0].split(" ")

    # The following two lines parse the first two elements of the numlist array as integers representing the number of sheep and wolves
    sheep = int(numlist[0])
    wolve = int(numlist[1])

    # The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
    # If so, it prints the message "unsafe". Otherwise, it prints the message "safe".
    if wolve >= sheep:
        print("unsafe")  # Printing the message "unsafe" to the console
    else:
        print("safe")  # Printing the message "safe" to the console

if __name__ == "__main__":
    main()

# <END-OF-CODE>
