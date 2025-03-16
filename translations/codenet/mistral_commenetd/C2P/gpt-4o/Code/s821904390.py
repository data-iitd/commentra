# We include the standard input/output library

def main():  # The main function is the entry point of the program
    in_seconds = int(input())  # We read an integer input from the standard input and store it in the 'in_seconds' variable

    h = in_seconds // 3600  # We calculate the number of hours by dividing the input by the total number of seconds in an hour (3600) and storing the quotient in 'h'
    in_seconds %= 3600  # We calculate the remaining seconds by taking the modulus of the input with 3600 and storing the result in 'in_seconds'

    m = in_seconds // 60  # We calculate the number of minutes by dividing the remaining seconds by 60 and storing the quotient in 'm'
    in_seconds %= 60  # We calculate the remaining seconds by taking the modulus of the remaining seconds with 60 and storing the result in 'in_seconds'

    s = in_seconds  # We store the remaining seconds in 's'

    print(f"{h}:{m}:{s}")  # We print the hours, minutes, and seconds in the format "HH:MM:SS" using the print function

main()  # Call the main function to execute the program
# <END-OF-CODE>
