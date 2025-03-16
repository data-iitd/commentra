# Read the values of N (number of scores) and K (the number of scores to compare)
N, K = map(int, input().split())

# Read the list of scores
score = list(map(int, input().split()))

# Initialize the index for the first score to compare (mae) and the index for the second score (usiro)
mae = 0
usiro = K

# Loop through the scores, comparing the score at index 'mae' with the score at index 'usiro'
for i in range(N - K):
    # If the score at 'mae' is less than the score at 'usiro', print 'Yes'
    if score[mae] < score[usiro]:
        print('Yes')
    # Otherwise, print 'No'
    else:
        print('No')
    
    # Move to the next pair of scores by incrementing both indices
    mae += 1
    usiro += 1
