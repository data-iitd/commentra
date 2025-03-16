# Importing the necessary module for reading input
import sys

def main():
    # Initializing a list to hold 4 strings
    str_list = []
    
    # Loop to read 4 strings from user input
    for _ in range(4):
        str_list.append(input().strip())  # Read a string and store it in the list
    
    yes = 0  # Flag to indicate if a condition is met
    
    # Outer loop to iterate through the first 3 strings
    for u in range(3):
        # Inner loop to check conditions on characters of the strings
        for i in range(3):
            # Check if the characters in the strings meet the specified conditions
            if ((str_list[u][i] == str_list[u][i + 1] and 
                 (str_list[u + 1][i] == str_list[u][i] or 
                  str_list[u + 1][i + 1] == str_list[u][i])) or 
                (str_list[u + 1][i] == str_list[u + 1][i + 1] and 
                 (str_list[u][i] == str_list[u + 1][i] or 
                  str_list[u][i + 1] == str_list[u + 1][i]))):
                
                yes = 1  # Set flag to indicate a match was found
                print("YES")  # Output "YES"
                break  # Exit the inner loop
        
        # If a match was found, exit the outer loop
        if yes == 1:
            break
    
    # If no matches were found, output "NO"
    if yes == 0:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
