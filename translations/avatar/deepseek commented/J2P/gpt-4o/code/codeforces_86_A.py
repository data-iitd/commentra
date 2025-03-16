def power(a):
    res = 0
    while a > 0:
        res += 1
        a //= 10
    return res

def mult(a):
    pow = power(a)
    max_value = 0
    for j in range(pow):
        max_value = max_value * 10 + 9
    return a * (max_value - a)

def main():
    # Read two long integers from the input
    l = int(input())
    r = int(input())
    res = 0
    maxxes = [0] * 10
    temp = 0

    # Calculate the maximum product for each range and store it in the array maxxes
    for i in range(10):
        temp = temp * 10 + 9
        maxxes[i] = (temp // 2) * (temp - temp // 2)

    # Calculate the maximum product for the given ranges and update the result res
    res = max(mult(l), res)
    res = max(mult(r), res)
    temp = 0

    # Check if the middle value of the range is within the given range and update the result res accordingly
    for i in range(10):
        temp = temp * 10 + 9
        if l <= temp // 2 <= r:
            res = max(maxxes[i], res)

    # Print the final result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
