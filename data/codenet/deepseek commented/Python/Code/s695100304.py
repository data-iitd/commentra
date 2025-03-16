
n=int(input())  # Take an integer input for the number of elements in the list
x=list(map(int,input().split()))  # Take a space-separated string of integers and convert them to a list of integers
x.reverse()  # Reverse the list
print(*x)  # Print the reversed list with space-separated elements

