from typing import List, Tuple, Union

# Define a pair type with first integer and second string
P = Tuple[int, str]

# Initialize an array of pairs v with size n
v = [None] * 22

# Initialize a list of lists of integers d with size 33
d = [[] for _ in range(33)]

# Main function
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        if n == 0:
            break
        
        # Initialize d array for each test case
        for i in range(33):
            d[i].clear()
        
        # Process each test case
        v[:n] = [None] * n
        for i in range(n):
            # Initialize the first element of pair v[i] as 0
            v[i] = (0, "")
            
            # Read the name and number of students m for the current test case
            name, m = input().split()
            m = int(m)
            
            # For each student, read the number of absences a and update the scores accordingly
            for _ in range(m):
                a = int(input())
                
                # Calculate the effect of the current student's absences on the scores of other students
                v[i] = (v[i][0] + n - len(d[a]), name)
                
                # Update the scores of students who have the same number of absences as the current student
                for k in range(len(d[a])):
                    # Decrease the score of the student whose index is in d[a] by 1
                    v[d[a][k]] = (v[d[a][k]][0] - 1, v[d[a][k]][1])
                
                # Add the index of the current student to the list d[a]
                d[a].append(i)
        
        # Sort the pairs in the array v in ascending order based on their first elements
        v.sort(key=lambda x: x[0])
        
        # Print the name and the highest score of the student with the highest score
        print(v[0][0], v[0][1])

# Call the main function
main()

