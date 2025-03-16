#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// getNextInt reads and converts the next integer from the input stream to an int
int getNextInt(istream& is) {
    string line;
    getline(is, line);
    return stoi(line);
}

// main function is the entry point of the program
int main(int argc, char* argv[]) {
    // open standard input as default file if no arguments are provided
    istream* fp = &cin;
    // open output file if provided as an argument
    ostream* wfp = &cout;
    if (argc > 1) {
        fp = new ifstream(argv[1]);
        // create output file if provided as an argument
        if (argc > 2) {
            wfp = new ofstream(argv[2]);
        }
    }

    // initialize input stream and writer
    istringstream iss(*fp);
    ostringstream oss;

    // read the first integer from the input
    int n = getNextInt(iss);

    // initialize answer variable
    string ans = "second";
    // iterate through the input integers
    for (int i = 0; i < n; i++) {
        // read the next integer from the input
        int a;
        iss >> a;
        // check if the current integer is odd
        if (a % 2 == 1) {
            // update the answer if an odd integer is found
            ans = "first";
            // exit the loop if only one odd integer is found
            break;
        }
    }
    // write the answer to the output
    *wfp << ans << endl;

    // close the files if they were opened
    if (argc > 1) {
        delete fp;
        if (argc > 2) {
            delete wfp;
        }
    }

    return 0;
}
