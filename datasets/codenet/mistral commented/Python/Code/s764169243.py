# Import necessary modules and define input function
import sys
input = sys.stdin.buffer.readline

# Define a helper class SegmentTree for range queries and updates
class SegmentTree:
    # Initialize the SegmentTree with given size and default value
    def __init__(self, size, default):
        self.size = 2**(size-1).bit_length()  # Calculate the size of the tree
        self.default = default            # Set the default value
        self.seg = [default]*(2*self.size-1) # Initialize the segment tree array

    # Define a function to calculate the segment tree value based on x and y
    def segfunc(self,x,y):
        return max(x,y)

    # Update a node in the segment tree
    def update(self,k,x):
        k += self.size-1              # Adjust the index for segment tree
        self.seg[k] = x               # Update the node value
        while k:                      # Propagate the change up the tree
            k = (k-1)//2
            self.seg[k] = self.segfunc(self.seg[2*k+1],self.seg[2*k+2])

    # Query the segment tree value for a given range [p, q)
    def query(self,p,q):
        if q <= p:                   # Return default value if p > q
            return self.default
        p += self.size-1;q += self.size-2 # Adjust the indices for segment tree
        ret = self.default            # Initialize the result
        while q-p > 1:                # Traverse the tree to find the answer
            if p&1 == 0:              # If p is even, update the result
                ret = self.segfunc(ret,self.seg[p])
            if q&1 == 1:              # If q is odd, update the result and q
                ret = self.segfunc(ret,self.seg[q])
                q -= 1
            p = p//2                 # Move to the parent node
            q = (q-1)//2
        ret = self.segfunc(self.seg[p],self.seg[q]) # Get the final answer
        return ret

    # Print the segment tree for debugging purposes
    def seg_print(self):
        print(self.seg)

# Read the input and initialize the variables
N = int(input())
a = list(map(int,input().split()))
ans = [i+1 for i in range(N)] # Initialize the answer list

# Initialize the segment trees for left and right ranges
left_seg = SegmentTree(N, 0)
for i, num in enumerate(a):    # Iterate through the input array and update the segment tree
    ans[num-1] *= i + 1 - left_seg.query(0,num) # Update the answer based on the segment tree query
    left_seg.update(num-1, i+1) # Update the segment tree

right_seg = SegmentTree(N, 0)
for i, num in enumerate(a[::-1]): # Iterate through the input array in reverse order and update the segment tree
    ans[num-1] *= i + 1 - right_seg.query(0,num) # Update the answer based on the segment tree query
    right_seg.update(num-1, i+1) # Update the segment tree

# Print the final answer
print(sum(ans))

# Main function to run the code
if __name__ == "__main__":
    main()
