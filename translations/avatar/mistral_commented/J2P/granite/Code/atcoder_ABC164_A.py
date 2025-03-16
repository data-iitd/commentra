
import sys  # Importing the Python built-in module sys

Sheep, Wolve = map ( int, input ( ).split ( ) )  # Reading the number of sheep and wolves from the console and converting them to integers

if Wolve >= Sheep:  # Checking if the number of wolves is greater than or equal to the number of sheep
    print ( "unsafe" )  # Printing the message "unsafe" to the console
else:
    print ( "safe" )  # Printing the message "safe" to the console

