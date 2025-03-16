# Import the necessary module
import sys

def main():
    # Read the number of friends
    n = int(input())
    
    # Lists to keep track of the number of male and female friends per day
    FfriendPerDay = [0] * 367  # List for female friends
    MfriendPerDay = [0] * 367  # List for male friends
    
    # Variable to store the maximum number of friends present on any day
    answer = 0
    
    # Loop through each friend to gather their availability
    for _ in range(n):
        # Read the gender of the friend (M for male, F for female)
        c = input().strip()
        # Read the start day (a) and end day (b) of availability
        a, b = map(int, input().split())
        
        # Loop through the days from a to b
        for j in range(a, b + 1):
            # Increment the count for male or female friends based on gender
            if c == 'M':
                MfriendPerDay[j] += 1
            else:
                FfriendPerDay[j] += 1
            
            # Check which gender has more friends on that day and update the answer
            if MfriendPerDay[j] < FfriendPerDay[j]:
                # If females are more, check if their count is greater than the current answer
                if MfriendPerDay[j] > answer:
                    answer = MfriendPerDay[j]
            else:
                # If males are more or equal, check if their count is greater than the current answer
                if FfriendPerDay[j] > answer:
                    answer = FfriendPerDay[j]
    
    # Output the maximum number of friends present on any day multiplied by 2
    print(answer * 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
