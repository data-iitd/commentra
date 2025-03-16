def main():
    n = int(input())

    for _ in range(n):
        s = input().strip()

        st = set()
        st.add(s)

        for j in range(1, len(s)):
            res = s[:j]
            res2 = s[j:]

            t = res
            t2 = res2

            st.add(t[::-1] + t2)
            st.add(t2 + t[::-1])

            st.add(t + res2[::-1])
            st.add(res2[::-1] + t)

            st.add(res[::-1] + t2)
            st.add(t2 + res[::-1])

            st.add(res + res2[::-1])
            st.add(res2[::-1] + res)

        print(len(st))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
