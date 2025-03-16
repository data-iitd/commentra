# Read two integers A and B from user input
A, B = map(int, input().split())

# Check if both players have the same score
if A == B:
    print("Draw")  # If scores are equal, it's a draw
# Check if Alice has the score of 1
elif A == 1:
    print("Alice")  # If Alice's score is 1, she wins
# Check if Bob has the score of 1
elif B == 1:
    print("Bob")  # If Bob's score is 1, he wins
# Check if Alice's score is greater than Bob's
elif A > B:
    print("Alice")  # If Alice's score is higher, she wins
# If none of the above conditions are met, Bob wins
else:
    print("Bob")  # If Bob's score is higher, he wins
