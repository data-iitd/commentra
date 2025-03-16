
inp = int(input())  # Taking an integer input from the user
lista = []
lista = [int(x) for x in input().split()]  # Converting the input string into a list of integers

# Iterating through the list of integers
for i in range(len(lista)):
    # For the first element in the list
    if i == 0:
        print(f"{lista[i+1] - lista[i]} {lista[len(lista)-1] - lista[i]}")  # Printing the differences
        continue
    # For the last element in the list
    elif i == len(lista) - 1:
        print(f"{lista[len(lista)-1] - lista[len(lista)-2]} {lista[len(lista)-1] - lista[0]}")  # Printing the differences
        continue
    # For other elements in the list
    elif lista[i] - lista[i - 1] > lista[i + 1] - lista[i]:
        print(lista[i + 1] - lista[i], end=" ")  # Printing the difference between the next and current integer
    else:
        print(lista[i] - lista[i - 1], end=" ")  # Printing the difference between the current and previous integer
    # Printing the difference between the last and current integer or the first and current integer
    if lista[len(lista) - 1] - lista[i] > lista[i] - lista[0]:
        print(lista[len(lista) - 1] - lista[i])  # Printing the difference between the last and current integer
    else:
        print(lista[i] - lista[0])  # Printing the difference between the first and current integer

