
N = int(input())  # Taking an integer input N, which represents some quantity or number of items.
capacity_list = [int(input()) for _ in range(5)]  # Taking five integer inputs and storing them in a list called capacity_list.
capacity_list.sort()  # Sorting the capacity_list in ascending order.
bottle_neck = capacity_list[0]  # Assigning the smallest capacity in the sorted list to a variable called bottle_neck.
print(4+int((N+bottle_neck-1)/bottle_neck))  # Calculating and printing the result of a specific formula.

