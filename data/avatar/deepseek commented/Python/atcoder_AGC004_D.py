
import sys
sys.setrecursionlimit ( 10 ** 6 )  # Step 1: Set the recursion limit to prevent overflow

def dfs ( links , n , k , v , p ) :  # Step 2: Define the DFS function
    height_from_leaf = 0  # Initialize the height from the leaf node
    cut_count = 0  # Initialize the count of cuts
    for u in links [ v ] :  # Step 3: Traverse the tree
        if u == 0 :  # Skip if the node is the root (0)
            continue
        hgt , cut = dfs ( links , n , k , u , v )  # Recursively call DFS
        height_from_leaf = max ( height_from_leaf , hgt )  # Update the height from the leaf
        cut_count += cut  # Count the number of cuts
    height_from_leaf += 1  # Increment the height from the leaf node
    if p != 0 and height_from_leaf == k :  # Step 4: Check if a cut is needed
        height_from_leaf = 0  # Reset the height
        cut_count += 1  # Increment the cut count
    return height_from_leaf , cut_count  # Step 5: Return the height and cut count

n , k , * aaa = map ( int , sys.stdin.buffer.read ( ).split ( ) )  # Step 6: Read input data
links = [ set ( ) for _ in range ( n ) ]  # Initialize the tree structure
for i , a in enumerate ( aaa ) :  # Step 7: Build the tree
    a -= 1
    links [ a ].add ( i )
_, ans = dfs ( links , n , k , 0 , 0 )  # Step 8: Perform DFS starting from the root
if aaa [ 0 ] != 1 :  # Step 9: Adjust the answer if necessary
    ans += 1
print ( ans )  # Step 10: Output the final result

