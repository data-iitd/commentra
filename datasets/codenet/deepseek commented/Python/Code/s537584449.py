
# Step 1: The code starts by taking an integer input from the user.
a = int(input())

# Step 2: The function `func` is defined to take one parameter `a`.
def func(a):
    # Step 3: Inside the function, an empty list `digits` is initialized.
    digits = []
    # Step 4: The variable `temp` is assigned the value of `a` and a while loop is used to extract each digit of `a` and append it to the `digits` list.
    temp = a
    while temp != 0:
        digits.append(temp%10)
        temp = int(temp/10)
    # Step 5: The while loop continues until `temp` becomes 0.
    
    # Step 6: The sum of the digits in the `digits` list is calculated and stored in the variable `result`.
    result = sum(digits)
    
    # Step 7: A conditional statement checks if `result` is equal to 1. If true, it prints '10'; otherwise, it prints `result`.
    if result == 1:
        print('10')
    else:
        print(result)

# Step 8: The function `func` is called with the input integer `a`.
func(a)

