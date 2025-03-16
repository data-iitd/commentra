# Read an integer input (not used later in the code)
inp = int(input())

# Initialize an empty list to store integers
lista = []

# Read a line of input, split it into strings, convert each string to an integer, and store it in lista
lista = [int(x) for x in input().split()]

# Iterate through the indices of the lista
for i in range(len(lista)):
    # Handle the first element in the list
    if i == 0:
        # Calculate and print the difference between the second and first elements,
        # and the difference between the last and first elements
        print(f"{lista[i+1] - lista[i]} {lista[len(lista)-1] - lista[i]}")
        continue  # Skip to the next iteration

    # Handle the last element in the list
    elif i == len(lista) - 1:
        # Calculate and print the difference between the last and second-to-last elements,
        # and the difference between the last and the first elements
        print(f"{lista[len(lista)-1] - lista[len(lista)-2]} {lista[len(lista)-1] - lista[0]}")
        continue  # Skip to the next iteration

    # For elements in the middle of the list
    elif lista[i] - lista[i - 1] > lista[i + 1] - lista[i]:
        # If the difference to the next element is smaller, print that difference
        print(lista[i + 1] - lista[i], end=" ")
    else:
        # Otherwise, print the difference to the previous element
        print(lista[i] - lista[i - 1], end=" ")

    # Compare the difference to the last element with the difference to the first element
    if lista[len(lista) - 1] - lista[i] > lista[i] - lista[0]:
        # If the difference to the last element is larger, print that difference
        print(lista[len(lista) - 1] - lista[i])
    else:
        # Otherwise, print the difference to the first element
        print(lista[i] - lista[0])
