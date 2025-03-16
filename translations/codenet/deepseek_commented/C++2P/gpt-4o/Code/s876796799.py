def main():
    import sys
    from sortedcontainers import SortedSet

    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of elements
    a = list(map(int, data[1:N + 1]))  # Read the elements into array a
    ind_a = [0] * N  # Array to store the indices of elements in array a

    for i in range(N):
        ind_a[a[i] - 1] = i  # Initialize ind_a with the indices of elements in array a

    used_inds = SortedSet()  # Set to keep track of used indices
    ans = 0  # Variable to store the final answer

    for i in range(N):
        left_border = -1  # Variable to store the left boundary
        right_border = N  # Variable to store the right boundary
        cur_ind = ind_a[i]  # Current index of the element being processed

        left_it = used_inds.bisect_left(cur_ind)  # Get the position of the lower bound of cur_ind in used_inds
        right_it = used_inds.bisect_left(cur_ind + 1)  # Get the position of the lower bound of cur_ind + 1 in used_inds

        if left_it > 0:
            left_border = used_inds[left_it - 1]  # Set left_border to the value before cur_ind if it exists

        if right_it < len(used_inds):
            right_border = used_inds[right_it]  # Set right_border to the value at right_it if it exists

        ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)  # Calculate the contribution of the current element to the answer

        used_inds.add(cur_ind)  # Insert the current index into the set used_inds

    print(ans)  # Output the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
