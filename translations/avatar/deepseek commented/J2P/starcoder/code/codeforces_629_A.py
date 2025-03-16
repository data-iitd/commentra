
import sys

def main():
    # Read the size of the grid
    num = int(input())

    # Read num strings representing the grid rows
    arr = []
    for i in range(num):
        arr.append(input())

    # Calculate the fine for each column
    fine = 0
    for i in range(num):
        counter = 0
        for k in range(num):
            if arr[k][i] == 'C':
                counter += 1
        fine += (counter * (counter - 1)) // 2

    # Calculate the fine for each row
    for i in range(num):
        counter = 0
        for k in range(num):
            if arr[i][k] == 'C':
                counter += 1
        fine += (counter * (counter - 1)) // 2

    # Print the total fine
    print(fine)

if __name__ == "__main__":
    main()

# 