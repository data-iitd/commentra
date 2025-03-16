
n=int(input())  # Read the number of pairs
ls=[list(map(int,input().split())) for i in range(n)]  # Read the pairs and store them in a list
ls=sorted(ls,key=lambda x:sum(x),reverse=True)  # Sort the list based on the sum of each pair in descending order
taka=sum([ls[i][0] for i in range(0,len(ls),2)])  # Calculate the sum of the first elements of every second pair and store it in taka
aoki=sum([ls[i][1] for i in range(1,len(ls),2)])  # Calculate the sum of the second elements of every second pair and store it in aoki

print(taka-aoki)  # Print the difference between taka and aoki

