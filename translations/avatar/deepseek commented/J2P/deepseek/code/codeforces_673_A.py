def main():
    n = int(input())  # Read the number of elements in the list `a`
    a = list(map(int, input().split()))  # Read each integer value and store in list `a`
    
    result, pos, flag = 0, 0, 0
    
    if a[0] > 15:
        result = 15  # If the first element is greater than 15, set result to 15
    else:
        for i in range(1, n):
            if a[i] - a[i - 1] > 15:
                pos = i - 1  # Find the position where the difference is greater than 15
                flag = 1  # Set flag to 1 indicating such a position is found
                break
        if flag == 1:
            result = a[pos] + 15  # Set result to the element at pos plus 15
        else:
            result = a[-1] + 15  # Otherwise, set result to the last element plus 15
    
    if result > 90:
        result = 90  # If result is greater than 90, set it to 90
    
    print(result)  # Print the final result


main()
