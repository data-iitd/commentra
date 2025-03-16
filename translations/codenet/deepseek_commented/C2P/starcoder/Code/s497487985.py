# Define macros for maximum and minimum values
def MAX(X, Y):
    return X if X > Y else Y

def MIN(X, Y):
    return X if X < Y else Y

# Function to compare integers in descending order
def compare_int(a, b):
    return b - a

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    return gcd(b, a % b) if b else a

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a * b / gcd(a, b)

# Main function
if __name__ == "__main__":
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    point = [0] * n
    for i in range(q):
        point[a[i] - 1] += 1
    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")
        else:
            print("No")

