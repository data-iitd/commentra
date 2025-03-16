
import sys

def main():
    # Reads the number of arms.
    n = int(input())
    
    # Defines a class to represent an arm with left and right endpoints.
    class Arm:
        def __init__(self, x, l):
            self.l = x - l
            self.r = x + l
    
    # Creates a list to store the arms.
    as = [Arm(int(x), int(l)) for x, l in zip(*[iter(sys.stdin.read().split())]*2)]
    
    # Sorts the arms based on their right endpoints.
    as.sort(key=lambda a: a.r)
    
    # Initializes the answer and the right endpoint reference.
    ans = 1
    r = as[0].r
    
    # Iterates through the sorted arms to count non-overlapping arms.
    for a in as[1:]:
        if a.l >= r:
            ans += 1
            r = a.r
    
    # Prints the count of non-overlapping arms.
    print(ans)

