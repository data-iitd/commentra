# Importing the necessary module for input
import sys

def main():
    input = sys.stdin.read
    data = input().split()  # Read all input at once and split into a list
    N = int(data[0])  # Read the first integer N
    K = int(data[1])  # Read the second integer K
    S = data[2]  # Read the string S
    
    c1 = list(S)  # Convert the string S to a list c1
    c3 = list(S)  # Convert the string S to a list c3
    
    flag = False  # A flag to indicate whether we are flipping
    count = 0  # A counter for the number of flips
    
    # Process c1 (Left to Right)
    for i in range(N):
        if flag and c1[i] == 'R':  # If we are flipping and encounter 'R'
            flag = False  # Reset the flag
            count += 1  # Increment the flip count
        if count == K:  # If we have made K flips, break out of the loop
            break
        if c1[i] == 'L':  # If we encounter 'L'
            flag = True  # Set the flag to true
            c1[i] = 'R'  # Flip it to 'R'
    
    flag = False  # Reset the flag
    count = 0  # Reset the flip count
    
    # Process c3 (Right to Left)
    for i in range(N):
        if flag and c3[i] == 'L':  # If we are flipping and encounter 'L'
            flag = False  # Reset the flag
            count += 1  # Increment the flip count
        if count == K:  # If we have made K flips, break out of the loop
            break
        if c3[i] == 'R':  # If we encounter 'R'
            flag = True  # Set the flag to true
            c3[i] = 'L'  # Flip it to 'L'
    
    S1 = ''.join(c1)  # Convert the modified c1 back to a string S1
    S3 = ''.join(c3)  # Convert the modified c3 back to a string S3
    
    count = 1  # Initialize count for consecutive characters
    sum1 = 0  # Initialize sum for S1
    bef = S1[0]  # Initialize the previous character
    
    # Count consecutive characters in S1
    for i in range(1, N):
        if S1[i] == bef:  # If the current character is the same as the previous
            count += 1  # Increment the count
            if i == N - 1:  # If it's the last character in the string
                sum1 += count - 1  # Add the count minus one to the sum
        else:  # If the current character is different
            bef = S1[i]  # Update the previous character
            sum1 += count - 1  # Add the count minus one to the sum
            count = 1  # Reset the count
    
    count = 1  # Reset count for consecutive characters
    sum3 = 0  # Initialize sum for S3
    bef = S3[0]  # Initialize the previous character
    
    # Count consecutive characters in S3
    for i in range(1, N):
        if S3[i] == bef:  # If the current character is the same as the previous
            count += 1  # Increment the count
            if i == N - 1:  # If it's the last character in the string
                sum3 += count - 1  # Add the count minus one to the sum
        else:  # If the current character is different
            bef = S3[i]  # Update the previous character
            sum3 += count - 1  # Add the count minus one to the sum
            count = 1  # Reset the count
    
    # Print the maximum of the two sums
    print(max(sum1, sum3))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
