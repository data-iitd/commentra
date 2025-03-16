import sys

def get_next_string(scanner):
    return next(scanner)

def get_next_int(scanner):
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    return int(get_next_string(scanner))

def get_next_uint64(scanner):
    return int(get_next_string(scanner))

def get_next_float64(scanner):
    return float(get_next_string(scanner))

def solve(scanner, writer):
    k = get_next_int(scanner)
    x = get_next_int(scanner)

    ans = "No"
    if k * 500 >= x:
        ans = "Yes"
    writer.write(ans + "\n")

def main():
    cnt = 0
    input_source = sys.stdin
    output_source = sys.stdout

    if "MASPY" in os.environ and os.environ["MASPY"] == "ますピ":
        input_source = open(os.environ["BEET_THE_HARMONY_OF_PERFECT"])
        cnt = 2
    if "MASPYPY" in os.environ and os.environ["MASPYPY"] == "ますピッピ":
        output_source = open(os.environ["NGTKANA_IS_GENIUS10"], 'w')

    scanner = iter(input_source.read().split())
    writer = output_source

    solve(scanner, writer)
    for _ in range(cnt):
        writer.write("-----------------------------------\n")
        solve(scanner, writer)

    writer.flush()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
