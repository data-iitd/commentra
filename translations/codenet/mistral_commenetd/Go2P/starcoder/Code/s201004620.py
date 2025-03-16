# Python code to illustrate switch case

# Function to print the weather condition
def printWeather(S):
  # Switch statement to check the value of the string S and print the corresponding weather condition
  if S == "Sunny":
    print("Cloudy")
  elif S == "Cloudy":
    print("Rainy")
    elif S == "Rainy":
      print("Sunny")

# Driver Code
if __name__ == '__main__':
  # Declare a variable named S of type string
  S = ""

  # Read a string input from the standard input using input()
  S = input()

  # Function call to print the weather condition
  printWeather(S)

# End of the code

