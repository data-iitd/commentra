
#include <bits/stdc++.h>

using namespace std ;

class FastReader {
    public:
        FastReader() {
            br = new ifstream("input.txt");
        }

        string next() {
            while (st == NULL || !st->hasMoreElements()) {
                try {
                    st = new stringstream(br->readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st->nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        string nextLine() {
            string str = "" ;
            try {
                str = br->readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str ;
        }

    private:
        ifstream *br ;
        stringstream *st ;
};

FastReader scan = new FastReader();  // Creating an instance of FastReader

int main() {
    int t = scan.nextInt();  // Reading the number of test cases
    int arr[t];  // Creating an integer array of size 't' to store the input

    for (int i = 0; i < t; i++) {  // Iterating through the array
        arr[i] = scan.nextInt();  // Reading each element

        if (arr[i] == 1) {  // Checking if the current element is 1
            if (prevWinner == 0) {  // If the previous winner was 0
                prevWinner = 2;  // Update the 'prevWinner' variable to 2
            }

            if ((arr[i] - 1) % 2 == 0) {  // Checking the parity of the current element's index
                cout << (prevWinner == 0 ? 2 : 1) << endl;  // Printing the output based on the 'prevWinner' value
                prevWinner = (prevWinner == 0 ? 2 : 1);  // Updating the 'prevWinner' variable for the next iteration
            }
        }
    }

    return 0;
}

int prevWinner = 0;  // Initializing the 'prevWinner' variable to 0

