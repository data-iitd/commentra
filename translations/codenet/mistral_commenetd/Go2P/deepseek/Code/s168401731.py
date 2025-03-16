import sys
import io

def get_next_string(scanner):
    return scanner.readline().strip()

def get_next_int(scanner):
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    return int(get_next_string(scanner))

def get_next_uint64(scanner):
    return int(get_next_string(scanner))

def get_next_float64(scanner):
    return float(get_next_string(scanner))

def main():
    # open standard input as default file if no arguments are provided
    fp = sys.stdin
    # open output file if provided as an argument
    wfp = sys.stdout
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
        # create output file if provided as an argument
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    # initialize scanner and writer
    scanner = io.TextIOWrapper(fp)
    writer = io.TextIOWrapper(wfp)

    # read the first integer from the input
    n = get_next_int(scanner)

    # initialize answer variable
    ans = "second"
    # iterate through the input integers
    for i in range(n):
        # read the next integer from the input
        a = get_next_int(scanner)
        # check if the current integer is odd
        if a % 2 == 1:
            # update the answer if an odd integer is found
            ans = "first"
            # exit the loop if only one odd integer is found
            break

    # write the answer to the output
    writer.write(ans + '\n')
    # flush the writer buffer
    writer.flush()

# Call the main function
main()

