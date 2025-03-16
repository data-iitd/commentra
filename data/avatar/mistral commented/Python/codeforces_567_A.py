# Take an integer input from the user
inp = int(input())

# Create an empty list to store the input integers
lista = []

# Populate the list 'lista' with integers input by the user, separated by spaces
lista = [int(x) for x in input().split()]

# Iterate through each index 'i' in the list 'lista'
for i in range(len(lista)):
    # If 'i' is the first index
    if i == 0:
        # Print the difference between the second and first elements and the difference between the last and first elements
        print(f"{lista[i+1] - lista[i]} {lista[-1] - lista[i]}")
        continue

    # If 'i' is the last index
    elif i == len(lista) - 1:
        # Print the difference between the last and second last element and the difference between the last and first element
        print(f"{lista[-1] - lista[-2]} {lista[-1] - lista[0]}")
        continue

    # If the difference between the current index and the previous index is greater than the difference between the next index and the current index
    elif lista[i] - lista[i-1] > lista[i+1] - lista[i]:
        # Print the difference between the next index and the current index
        print(lista[i+1] - lista[i], end=" ")

    # If the difference between the current index and the previous index is less than or equal to the difference between the next index and the current index
    else:
        # Print the difference between the current index and the previous index and the difference between the current index and the first index
        print(lista[i] - lista[i-1], end=" ")
        if lista[-1] - lista[i] > lista[i] - lista[0]:
            print(lista[-1] - lista[i])
        else:
            print(lista[i] - lista[0])
