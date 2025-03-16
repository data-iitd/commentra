def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n = int(input())  # Number of people
    k = int(input())  # Total points
    q = int(input())  # Number of queries
    a = [0] * 100001  # Array to store the query numbers
    point = [0] * 100001  # Array to store the current points for each person

    # Check if it's possible to distribute the points to all queries
    if q < k:
        # If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
        for i in range(n):
            print("Yes")  # This will never be reached
        return

    # Distribute the points to each query one by one
    for i in range(q):
        a[i] = int(input())  # Read the query number
        point[a[i] - 1] += 1  # Increase the points for the person with the query number

    # Check if it's possible to distribute the remaining points to the remaining people
    for i in range(n):
        if k - (q - point[i]) > 0:  # If the remaining points are greater than the difference between the total points and the points already distributed
            print("Yes")  # It's possible to distribute the remaining points to the remaining people
        else:
            print("No")  # It's impossible to distribute the remaining points to the remaining people

if __name__ == "__main__":
    main()

# <END-OF-CODE>
