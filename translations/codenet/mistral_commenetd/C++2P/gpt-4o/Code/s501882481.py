def to_string(s):
    return s

def to_string_pair(p):
    return f"{{{to_string(p[0])},{to_string(p[1])}}}"

def to_string_vector(v):
    return "{" + ",".join(to_string(x) for x in v) + "}"

def debug(*args):
    print(" ".join(to_string(x) for x in args))

def print_multiple(*args):
    print("".join(to_string(x) for x in args))

def get():
    return

def get_multiple(*args):
    for arg in args:
        arg[0] = input()

def get_vector(vec):
    for i in range(len(vec)):
        vec[i] = input()

if __name__ == "__main__":
    S = input()  # Get input for the string variable S

    if S == "Sunny":  # Check if the string is equal to "Sunny"
        print_multiple("Cloudy")  # If true, print "Cloudy"
    elif S == "Cloudy":  # Check if the string is equal to "Cloudy"
        print_multiple("Rainy")  # If true, print "Rainy"
    else:  # If neither of the conditions are true
        print_multiple("Sunny")  # Print "Sunny"

# <END-OF-CODE>
