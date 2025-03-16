
# Main function where the program execution begins
while True:
    # Take input in the format a S b
    a, S, b = input().split()
    
    # Perform operations based on the value of S
    if S == '+': print(int(a) + int(b))
    if S == '-': print(int(a) - int(b))
    if S == '*': print(int(a) * int(b))
    if S == '/': print(int(a) / int(b))
    
    # Break the loop if S is '?'
    if S == '?': break

