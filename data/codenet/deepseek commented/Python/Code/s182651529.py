
N, K = map(int, input().split())  # Read two integers N and K from input
score = list(map(int, input().split()))  # Read a list of scores

# Initialize two pointers, mae and usiro, to 0 and K, respectively
mae = 0
usiro = K

# Loop through N-K times
for i in range(N - K):
    # Compare the score at the mae pointer with the score at the usiro pointer
    if score[mae] < score[usiro]:
        print('Yes')  # Print 'Yes' if the score at usiro is greater than the score at mae
    else:
        print('No')  # Print 'No' otherwise
    
    # Increment both mae and usiro by 1
    mae += 1
    usiro += 1

