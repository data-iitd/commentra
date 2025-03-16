import sys

class Main:
    def __init__(self):
        self.MOD = 1000000007
        self.dp = [[0 for _ in range(13)] for _ in range(1000)]
        self.base = 1

    def run(self):
        # Read the input string and convert it to a character array
        cs = list(sys.stdin.readline().strip())

        # Iterate through the characters of the input from the last to the first
        for i in range(len(cs)):
            # Check if the current character is a '?', which can be any digit
            if cs[len(cs) - 1 - i] == '?':
                # Loop through all possible previous remainders
                for pre in range(13):
                    # Loop through all possible next digits (0-9)
                    for next in range(10):
                        # Update the dp array for the current position and remainder
                        self.dp[i][(self.base * next + pre) % 13] += (i > 0 and self.dp[i - 1][pre]) % self.MOD
                        # Ensure the result stays within the MOD limit
                        self.dp[i][(self.base * next + pre) % 13] %= self.MOD
            else:
                # If the character is a digit, convert it to an integer
                next = int(cs[len(cs) - 1 - i])
                # Loop through all possible previous remainders
                for pre in range(13):
                    # Update the dp array for the current position and remainder
                    self.dp[i][(self.base * next + pre) % 13] += (i > 0 and self.dp[i - 1][pre]) % self.MOD
                    # Ensure the result stays within the MOD limit
                    self.dp[i][(self.base * next + pre) % 13] %= self.MOD
            # Update the base value for the next iteration (moving to the next digit)
            self.base = self.base * 10 % 13

        # Output the result, which is the number of ways to form a number divisible by 13
        print(self.dp[len(cs) - 1][5])

# Create an instance of Main and run the main logic
if __name__ == '__main__':
    Main().run()

