
N = int(input())  # Take an integer input N, which represents the number of elements.
x = [eval(input().replace('JPY', '* 1.0').replace('BTC', '* 380000.0')) for i in range(N)]
# Create a list x, which contains elements that are the result of evaluating the input strings
# after replacing 'JPY' with '* 1.0' and 'BTC' with '* 380000.0'.
print(sum(x))  # Print the sum of the elements in the list x.

