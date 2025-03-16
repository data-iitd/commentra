def strrstr(string, pattern):
    offset = 0
    last_p = None

    while True:
        search_result = string.find(pattern, offset)
        if search_result == -1:
            break
        last_p = search_result
        offset = search_result + 1

    return last_p

def main():
    pattern_base = "keyence"
    S = input().strip()

    found = False

    for offset in range(len(pattern_base) + 1):
        top = pattern_base[:offset]
        bottom = pattern_base[offset:]

        top_search = S.find(top)
        if top_search != -1:
            bottom_search = strrstr(S[top_search + offset:], bottom)
            if bottom_search is not None:
                sep_count = 0

                if top_search != 0:
                    sep_count += 1
                if (top_search + offset) != (bottom_search + top_search + offset):
                    sep_count += 1
                if bottom_search + len(bottom) < len(S):
                    sep_count += 1

                if sep_count <= 1:
                    found = True
                    break

    print("YES" if found else "NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
