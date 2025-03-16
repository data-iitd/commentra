def main():
    import sys
    input = sys.stdin.readline
    n = int(input())

    for _ in range(n):
        s = input().strip()

        st = set()
        st.add(s)

        for j in range(1, len(s)):
            ss = ""
            for k in range(j):
                ss += s[k]
            res = ss

            ss2 = ""
            for k in range(j, len(s)):
                ss2 += s[k]
            res2 = ss2

            t = res
            t = t[::-1]
            t2 = res2
            t2 = t2[::-1]

            st.add(t + t2)
            st.add(t2 + t)

            st.add(t + t2[::-1])
            st.add(t2[::-1] + t)

            st.add(t[::-1] + t2)
            st.add(t2 + t[::-1])

            st.add(t[::-1] + t2[::-1])
            st.add(t2[::-1] + t[::-1])

        print(len(st))


if __name__ == "__main__":
    main()
