import sys

class Solution:
    def solve(self, in_, out_):
        # Read the number of logs and the value of k
        n = in_.nextInt()
        k = in_.nextInt()

        # Read the lengths of the logs into an array
        logsLength = in_.readArray(n)

        # Initialize binary search bounds
        min = 1
        max = 1000000001

        # Perform binary search to find the minimum possible length
        while min < max:
            mid = (min + max) // 2

            # Check if it's possible to cut the logs with the current mid length
            if self.nei(mid, logsLength, k):
                max = mid
            else:
                min = mid + 1

        # Output the minimum length found
        out_.println(min)

    # Helper method to determine if logs can be cut with the given mid length
    def nei(self, mid, logsLength, k):
        for log in logsLength:
            k -= (log + mid - 1) // mid - 1

        # Return true if we can make the cuts within the limit of k
        return k >= 0

# 