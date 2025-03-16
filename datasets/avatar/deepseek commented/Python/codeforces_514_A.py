
ip = input()  # Taking an input from the user and storing it in the variable `ip`.
st = ""  # Initializing an empty string `st`.
if len(ip) != 1:  # Checking if the length of the input `ip` is not equal to 1.
    if ip[0] == "9":  # Checking if the first character of `ip` is "9".
        st = "9"  # Assigning "9" to `st`.
        ip = ip[1:]  # Removing the first character from `ip`.
    for i in ip:  # Iterating over the remaining characters in `ip`.
        if int(i) > 4:  # Checking if the integer value of the character is greater than 4.
            n = 9 - int(i)  # Calculating the difference between 9 and the integer value.
            st += str(n)  # Converting it to a string and appending it to `st`.
        else:  # If the integer value is not greater than 4.
            st += i  # Simply appending the character to `st`.
else:  # If the length of `ip` is 1.
    st = ip  # Assigning `ip` directly to `st`.
print(int(st))  # Printing the integer value of `st`.

