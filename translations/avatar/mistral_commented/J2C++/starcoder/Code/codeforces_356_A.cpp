
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initializing FastReader for reading input
    FastReader in = FastReader();

    int n = in.nextInt();  // Reading the number of elements in the array

    set < int > left;  // Creating a set to store the indices of elements in the sorted order
    int answer[n];  // Creating an array to store the answer for each index

    // Adding all the indices to the set and initializing the answer array with -1
    for (int i = 0; i < n; i++) {
        left.insert(i);
        answer[i] = -1;
    }

    int q = in.nextInt();  // Reading the number of queries

    // Processing each query
    while (q-- > 0) {
        int l = in.nextInt() - 1;  // Reading the left index of the query range
        int r = in.nextInt() - 1;  // Reading the right index of the query range
        int win = in.nextInt();  // Reading the winning index

        // Updating the answer for the winning index and all the indices between the left and right indices
        while (left.upper_bound(l)!= left.end() && *left.upper_bound(l) <= r) {
            int curr = *left.upper_bound(l);
            answer[curr] = win;
            left.erase(curr);
        }

        // Updating the answer for the winning index in the answer array
        answer[win - 1] = 0;

        // Adding the winning index back to the set
        left.insert(win - 1);
    }

    // Printing the answer for each index in the answer array
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

class FastReader {
public:
    // BufferedReader for reading input
    BufferedReader br;
    // StringTokenizer for reading input tokens
    StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null ||!st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }
}

