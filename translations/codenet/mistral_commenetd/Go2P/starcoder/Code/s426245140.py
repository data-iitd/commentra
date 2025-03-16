# Import the "fmt" package for formatted I/O
import "fmt"

# Define a variable named "s" of type string to store user input
def main():
  s = ""

  # Use "fmt.Scan" to read a string input from the standard input
  fmt.Scan(&s)

  # Check if the first three characters of the string "s" form an identical sequence
  if (s[0] == s[1] and s[1] == s[2]) or (s[1] == s[2] and s[2] == s[3]):
    # If the condition is true, print "Yes" to the standard output
    fmt.Println("Yes")
  else:
    # If the condition is false, print "No" to the standard output
    fmt.Println("No")

# End of code

