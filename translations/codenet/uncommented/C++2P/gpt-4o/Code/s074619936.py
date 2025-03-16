while True:
    str_input = input()
    if str_input == "0":
        break
    sum = 0
    for char in str_input:
        num = int(char)
        sum += num
    
    print(sum)

# <END-OF-CODE>
