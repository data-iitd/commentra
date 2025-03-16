

import sys
import math

# The main function is the entry point of the program.
def main():
    # Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
    io = Io()
    sys.stdout.flush()

    # Read the number n from the standard input.
    n = io.Int()

    # Initialize an array aa of length n to store the input integers.
    aa = [0] * n

    # Read n integers from the standard input and store them in the aa array using a for loop.
    for i in range(n):
        aa[i] = io.Int()

    # Compute the cumulative sum of the aa array using the CumSum function.
    cumsum = CumSum(aa)

    # Initialize a variable ans to store the answer.
    ans = 2020202020

    # Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
    for i in range(1, len(cumsum)-1):
        # Compute the absolute difference between the last cumulative sum and the current cumulative sum.
        diff1 = abs(cumsum[-1] - cumsum[i])

        # Compute the difference between the current cumulative sum and the first cumulative sum.
        diff2 = cumsum[i] - cumsum[0]

        # Keep the minimum of these two differences as the answer.
        ans = min(ans, diff1, diff2)

    # Print the answer using the PrintLn method of the Io struct.
    io.PrintLn(ans)

# The Io struct represents the standard input and output streams.
class Io:
    def __init__(self):
        self.tokens = []
        self.nextToken = 0

    # The Flush method of the Io struct ensures that all output is written before the program exits.
    def Flush(self):
        sys.stdout.flush()

    # The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
    def NextLine(self):
        return input()

    # The Next method of the Io struct reads a token from the standard input and returns it as a string.
    def Next(self):
        while self.nextToken >= len(self.tokens):
            line = self.NextLine()
            self.tokens = line.split()
            self.nextToken = 0
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r

    # The Int method of the Io struct reads an integer from the standard input and returns it.
    def Int(self):
        return int(self.Next())

    # The PrintLn method of the Io struct prints a line to the standard output.
    def PrintLn(self, *a):
        print(*a)

    # The Printf method of the Io struct prints a formatted line to the standard output.
    def Printf(self, format, *a):
        print(format, *a)

    # The PrintIntLn method of the Io struct prints an integer array to the standard output.
    def PrintIntLn(self, a):
        self.PrintLn(a)

    # The PrintStringLn method of the Io struct prints a string array to the standard output.
    def PrintStringLn(self, a):
        self.PrintLn(a)

    # The Log method logs a message to the standard error stream.
    def Log(self, name, value):
        print(f"{name}={value}", file=sys.stderr)

# The Abs function returns the absolute value of an integer.
def Abs(a):
    if a >= 0:
        return a
    else:
        return -a

# The Pow function returns the result of raising a to the power of b.
def Pow(p, q):
    return int(math.pow(p, q))

# The Min function returns the minimum of a list of integers.
def Min(*args):
    if len(args) == 0:
        raise Exception("funciton min() requires at least one argument.")
    res = args[0]
    for a in args:
        res = min(res, a)
    return res

# The Max function returns the maximum of a list of integers.
def Max(*args):
    if len(args) == 0:
        raise Exception("funciton max() requires at least one argument.")
    res = args[0]
    for a in args:
        res = max(res, a)
    return res

# The SortAsc function sorts an integer slice in ascending order.
def SortAsc(a):
    a.sort()
    return a

# The SortDesc function sorts an integer slice in descending order.
def SortDesc(a):
    a.sort(reverse=True)
    return a

# The GCD function returns the greatest common divisor of a and b.
def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)

# The LCM function returns the least common multiple of a and b.
def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

# The CumSum function computes the cumulative sum of an integer slice.
def CumSum(nums):
    sums = [0]
    for n in nums:
        sums.append(sums[-1] + n)
    return sums

# The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
def BisectLeft(nums, left, right, target):
    if left == right:
        if nums[left] == target:
            return left
        elif nums[left] < target:
            return left + 1
        else:
            return left
    mid = (left + right) // 2
    if nums[mid] == target:
        return mid
    if nums[mid] > target:
        return BisectLeft(nums, left, mid, target)
    else:
        return BisectLeft(nums, mid+1, right, target)

# The Permutations function returns all permutations of a slice.
def Permutations(nums):
    size = len(nums)
    result = []

    def helper(nums, left, right):
        if left == right:
            result.append(nums[:])
            return
        for i in range(left, right+1):
            helper(nums, left+1, right)
            if i!= left:
                nums[left], nums[i] = nums[i], nums[left]
            result.append(nums[:])
            nums[left], nums[i] = nums[i], nums[left]

    helper(nums, 0, size-1)
    return result

# The remove function removes the first occurrence of x from a slice.
def remove(nums, x):
    result = []
    for n in nums:
        if n!= x:
            result.append(n)
    return result

# The PowerSet function returns all subsets of a slice.
def PowerSet(nums):
    size = len(nums)
    result = []

    def helper(nums, left, right, cur):
        if left == right {
            result.append(cur[:])
            return
        }
        for i := left; i <= right; i++ {
            cur = append(cur, nums[i])
            helper(nums, i+1, right, cur)
        }
    }

    helper(nums, 0, size-1, []int{})
    return result

# The Combination function returns all combinations of size r from a slice.
def Combination(nums, r):
    size = len(nums)
    result = []

    def helper(nums, left, right, cur):
        if left == right {
            result = append(result, cur[:])
            return
        }
        for i := left; i <= right; i++ {
            cur = append(cur, nums[i])
            helper(nums, i+1, right, cur)
        }
    }

    helper(nums, 0, size-1, []int{})
    return result

# The PrintIntLn function prints an integer array to the standard output.
def PrintIntLn(a):
    for _, v := range a {
        fmt.Fprintln(os.Stdout, v)
    }

// The PrintStringLn function prints a string array to the standard output.
def PrintStringLn(a):
    for _, v := range a {
        fmt.Fprintln(os.Stdout, v)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdout, format, a...)
    }

// The Printf function prints a formatted line to the standard output.
def Printf(format string, a...):
    fmt.Fprintf(os.Stdou