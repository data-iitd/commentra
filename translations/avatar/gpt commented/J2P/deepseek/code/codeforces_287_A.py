def main():
    # Reading 4 strings from user input
    str = [input() for _ in range(4)]
    
    # Outer loop to iterate through the first 3 strings
    for u in range(3):
        # Inner loop to check conditions on characters of the strings
        for i in range(2):
            # Check if the characters in the strings meet the specified conditions
            if (str[u][i] == str[u][i + 1] and 
                (str[u + 1][i] == str[u][i] or str[u + 1][i + 1] == str[u][i])) or \
               (str[u + 1][i] == str[u + 1][i + 1] and 
                (str[u][i] == str[u + 1][i] or str[u][i + 1] == str[u + 1][i])):
                
                print("YES")  # Output "YES"
                return  # Exit the function
    
    # If no matches were found, output "NO"
    print("NO")

# Call the main function
main()
