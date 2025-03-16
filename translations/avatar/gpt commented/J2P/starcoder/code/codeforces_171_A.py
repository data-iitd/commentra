
# FastReader class to handle fast input
class FastReader:
    def __init__(self):
        self.val = input()
    def next(self):
        self.val = self.val.split()
        return self.val.pop(0)
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())
    def nextLine(self):
        return str(self.next())

# Main function
if __name__ == '__main__':
    # Create an instance of FastReader for input
    sc = FastReader()

    # Read two integers n and m from input
    n = sc.nextInt()
    m = sc.nextInt()

    # Reverse the integer m and store the result in t
    t = reverse(m)

    # Print the sum of t and n
    print(t + n)

# Method to reverse the digits of an integer n
def reverse(n):
    # If n is a single digit, return n multiplied by 10
    if n < 10:
        return n * 10

    t = n
    r = 0

    # Loop to reverse the digits of n
    while t > 0:
        r = (r * 10) + t % 10
        t = t // 10

    # Return the reversed integer
    return r

