
from bisect import bisect_right , bisect_left
n , * l = map ( int , open ( 0 ).read ( ).split ( ) )
# Read input: n is the number of elements, l is the list of integers

l.sort ( )
# Sort the list l to prepare for binary search operations

ans = 0
# Initialize the answer variable to store the count of valid triangles

for i in range ( n ) :
    # Outer loop: iterate over each element in l
    for j in range ( i + 1 , n ) :
        # Inner loop: iterate over each element in l starting from i+1
        a = l [ i ]
        b = l [ j ]
        # a and b are the sides of the triangle being considered
        
        right = bisect_left ( l , a + b )
        # Find the leftmost index where a + b can be inserted to maintain sorted order
        
        left = bisect_right ( l , max ( a - b , b - a ) )
        # Find the rightmost index where max(a - b, b - a) can be inserted to maintain sorted order
        
        tmp = max ( 0 , right - left )
        # Calculate the number of valid elements that can form a triangle
        
        if left <= i < right :
            tmp -= 1
        # Adjust for overcounting if i is within the valid range
        
        if left <= j < right :
            tmp -= 1
        # Adjust for overcounting if j is within the valid range
        
        ans += tmp
        # Add the valid triangle count for the current pair to the total answer

print ( ans // 3 )
# Print the final answer, dividing by 3 as implied by the context

