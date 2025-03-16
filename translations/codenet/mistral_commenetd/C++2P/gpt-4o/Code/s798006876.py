MAX_N = int(1e3)  # maximum size of the array
data = [0] * MAX_N  # array to store input data

while True:
    try:
        m, nmi, nma = map(int, input().split())  # read input
        if nmi == 0:  # check if nmi is 0
            break
        for i in range(m):
            data[i] = int(input())  # read input data into the array
        ma = 0  # initialize maximum difference to 0
        ans = 0  # initialize answer to 0
        for i in range(nmi - 1, nma - 1):  # iterate through the subarray
            if ma <= data[i] - data[i + 1]:  # if current difference is greater than the previous maximum difference
                ans = i + 1  # update answer with the index of the current element
                ma = data[i] - data[i + 1]  # update maximum difference with the current difference
        print(ans)  # print the answer
    except EOFError:
        break  # exit loop on EOF

# <END-OF-CODE>
