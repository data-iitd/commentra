
# Define a pair type with first integer and second string
P = namedtuple('P', ['first','second'])

# Initialize an array of pairs v with size n
v = [P(0, '') for i in range(22)]

# Initialize a vector of integers d with size 33
d = [[] for i in range(33)]

# Main function
while True:
  # Read the number of test cases n
  n = int(input())
  if n == 0: break
  
  # Process each test case
  for i in range(n):
    # Initialize the first element of pair v[i] as 0
    v[i].first = 0
    
    # Read the name and number of students m for the current test case
    name, m = input().split()
    m = int(m)
    
    # For each student, read the number of absences a and update the scores accordingly
    for j in range(m):
      a = int(input())
      v[i].first += n - len(d[a])
      for k in range(len(d[a])):
	v[d[a][k]].first -= 1
      d[a].append(i)
    
    # Sort the pairs in the array v in ascending order based on their first elements
    v.sort(key=lambda x: x.first)
    
    # Print the name and the highest score of the student with the highest score
    print(v[0].first, v[0].second)

# 