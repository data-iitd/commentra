from collections import defaultdict

# Define a pair type with first integer and second string
class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Main function
def main():
    while True:
        n = int(input())
        if n == 0:
            break
        
        # Initialize d dictionary for each test case
        d = defaultdict(list)
        
        # Initialize an array of pairs v with size n
        v = [Pair(0, "") for _ in range(n)]
        
        # Process each test case
        for i in range(n):
            # Read the name and number of students m for the current test case
            v[i].second, m = input().split()
            m = int(m)
            
            # For each student, read the number of absences a and update the scores accordingly
            for _ in range(m):
                a = int(input())
                
                # Calculate the effect of the current student's absences on the scores of other students
                v[i].first += n - len(d[a])
                
                # Update the scores of students who have the same number of absences as the current student
                for index in d[a]:
                    v[index].first -= 1
                
                # Add the index of the current student to the list d[a]
                d[a].append(i)
        
        # Sort the pairs in the array v in ascending order based on their first elements
        v.sort(key=lambda x: (x.first, x.second))
        
        # Print the name and the highest score of the student with the highest score
        print(v[0].first, v[0].second)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
