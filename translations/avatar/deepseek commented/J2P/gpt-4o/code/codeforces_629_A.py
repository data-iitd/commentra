def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    num = int(data[0])  # Read the size of the grid
    counter = 0  # Counter for the number of 'C's
    fine = 0  # Fine amount to be calculated
    arr = []  # List to store the grid rows

    # Read num strings representing the grid rows
    for i in range(1, num + 1):
        s = data[i]
        arr.append(s)

    # Calculate the fine for each column
    for i in range(num):
        for k in range(num):
            if arr[k][i] == 'C':
                counter += 1
        fine += (counter * (counter - 1)) // 2  # Calculate the fine for the column
        counter = 0  # Reset the counter for the next column

    # Calculate the fine for each row
    for i in range(num):
        for k in range(num):
            if arr[i][k] == 'C':
                counter += 1
        fine += (counter * (counter - 1)) // 2  # Calculate the fine for the row
        counter = 0  # Reset the counter for the next row

    # Print the total fine
    print(fine)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
