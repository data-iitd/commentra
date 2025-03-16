#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istringstream &iss) {
    int i;
    iss >> i;
    return i;
}

// Main function handles the program's flow
int main() {
    ifstream fp;
    ofstream wfp;
    int cnt = 0;

    if (getenv("MASPY") && string(getenv("MASPY")) == "ますピ") {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        cnt = 2;
    } else {
        fp.open("/dev/stdin");
    }

    if (getenv("MASPYPY") && string(getenv("MASPYPY")) == "ますピッピ") {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    } else {
        wfp.open("/dev/stdout");
    }

    string line;
    while (getline(fp, line)) {
        istringstream iss(line);
        int k = getNextInt(iss);
        int x = getNextInt(iss);

        string ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        wfp << ans << endl;
    }

    for (int i = 0; i < cnt; i++) {
        wfp << "-----------------------------------" << endl;
        string line;
        if (getline(fp, line)) {
            istringstream iss(line);
            int k = getNextInt(iss);
            int x = getNextInt(iss);

            string ans = "No";
            if (k * 500 >= x) {
                ans = "Yes";
            }
            wfp << ans << endl;
        }
    }

    fp.close();
    wfp.close();
    return 0;
}

// <END-OF-CODE>
