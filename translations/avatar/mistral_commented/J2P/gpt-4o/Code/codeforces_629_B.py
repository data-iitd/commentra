# Importing the necessary module
import sys

def main():
    n = int(input())  # Reading the number of test cases

    FfriendPerDay = [0] * 367  # Initializing a list of size 367 to store the number of friends of type F for each day
    MfriendPerDay = [0] * 367  # Initializing a list of size 367 to store the number of friends of type M for each day
    answer = 0  # Initializing an integer variable to store the maximum difference

    for _ in range(n):  # Iterating through each test case
        c = input().strip()  # Reading the character representing the gender of the friend
        a, b = map(int, input().split())  # Reading the starting and ending day of the range

        for j in range(a, b + 1):  # Iterating through each day in the range
            if c == 'M':
                MfriendPerDay[j] += 1  # Incrementing the counter in the MfriendPerDay list for the day if the friend is of type M
            else:
                FfriendPerDay[j] += 1  # Incrementing the counter in the FfriendPerDay list for the day if the friend is of type F

            if MfriendPerDay[j] < FfriendPerDay[j]:  # Checking if the number of friends of type M is less than F
                if MfriendPerDay[j] > answer:
                    answer = MfriendPerDay[j]  # Updating the value of answer if the current difference is greater
            else:  # Checking for the number of friends of type F
                if FfriendPerDay[j] > answer:
                    answer = FfriendPerDay[j]

    print(answer * 2)  # Printing the answer, which is twice the maximum difference

if __name__ == "__main__":
    main()

# <END-OF-CODE>
