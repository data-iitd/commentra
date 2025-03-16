
# Function A definition goes here
def A(void):
    pass

# Function B definition goes here
def B(void):
    x = int(input())
    sum = 100
    i = 0
    while sum < x:
        sum += sum / 100
        i += 1
    print(i)

# Function C definition goes here
def C(void):
    pass

# Function D definition goes here
def D(void):
    pass

if __name__ == "__main__":
    # Call function B
    B()

# 