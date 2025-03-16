
# Python 3 program to find the answer to the problem

# Function to find the answer to the problem
def find_answer(a, N):
    # Initialize the answer to 0
    ans = 0

    # Initialize the set to keep track of used indices
    used_inds = set()

    # Loop through all the elements of the array
    for i in range(N):
        # Initialize the left and right boundaries
        left_border = -1
        right_border = N

        # Get the current index of the element being processed
        cur_ind = a[i] - 1

        # Get the lower bound of cur_ind in used_inds
        left_it = used_inds.lower_bound(cur_ind)

        # Get the lower bound of cur_ind + 1 in used_inds
        right_it = used_inds.lower_bound(cur_ind + 1)

        # If left_it is the first element, set left_border to -1
        if left_it == used_inds.begin():
            left_border = -1
        # If left_it points to an element greater than cur_ind, adjust left_it
        elif left_it == used_inds.end() or *left_it > cur_ind:
            left_it -= 1
        # Set left_border to the value pointed by left_it
        left_border = *left_it

        # If right_it is the end, set right_border to N
        if right_it == used_inds.end():
            right_border = N
        # Set right_border to the value pointed by right_it
        right_border = *right_it

        # Calculate the contribution of the current element to the answer
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((i + 1))

        # Insert the current index into the set used_inds
        used_inds.add(cur_ind)

    # Return the final answer
    return ans

# Driver Code
if __name__ == '__main__':
    # Read the number of elements
    N = int(input())

    # Read the elements into array a
    a = [int(x) for x in input().split()]

    # Find the answer to the problem
    ans = find_answer(a, N)

    # Output the final answer
    print(ans)

