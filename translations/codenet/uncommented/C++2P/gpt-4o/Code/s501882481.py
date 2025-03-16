def to_string(s):
    return s

def to_string_pair(p):
    return f"{{{to_string(p[0])},{to_string(p[1])}}}"

def to_string_list(v):
    return "{" + ",".join(to_string(x) for x in v) + "}"

def debug(*args):
    print(" ".join(to_string(x) for x in args), file=sys.stderr)

def print_output(*args):
    print("".join(to_string(x) for x in args))

def get_input():
    return input()

def get_input_list(size):
    return [input() for _ in range(size)]

if __name__ == "__main__":
    S = get_input()
    if S == "Sunny":
        print_output("Cloudy")
    elif S == "Cloudy":
        print_output("Rainy")
    else:
        print_output("Sunny")
# <END-OF-CODE>
