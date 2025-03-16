# Taking two inputs from the user
input_first = input("Enter first list: ")
input_second = input("Enter second list: ")

# Using map() function to apply a lambda function to each element of the first input list and the corresponding element of the second input list
equal_elements = map(lambda x, y:x==y, input_first, input_second)

# Using sum() function to count the number of equal elements
number_of_equal_elements = sum(equal_elements)

# Printing the result
print("Number of equal elements: ", number_of_equal_elements)