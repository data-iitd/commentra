#include <iostream>
#include <vector>
#include <limits>

#define INF 0x5fffffff

std::vector<int> a(100002); // array to store input numbers
std::vector<int> b(100002); // array to store the minimum number of steps to reach from the start or end

std::string buf; // buffer to read input from stdin

// function to read an integer from the input buffer
int getint(std::string &input, size_t &pos) {
    int n = 0;
    bool negative = false;

    if (input[pos] == '-') { // check if the number is negative
        negative = true;
        pos++;
    }

    while (pos < input.size() && input[pos] >= '0' && input[pos] <= '9') {
        n = (n << 3) + (n << 1) + (input[pos++] - '0'); // read the digits
    }

    return negative ? -n : n; // return the number
}

int main() {
    int w, k, f, close, ans; // declare variables
    size_t pos = 0;

    // read the number of elements in the array 'a'
    std::getline(std::cin, buf);
    w = getint(buf, pos);

    // read the elements of array 'a'
    std::getline(std::cin, buf);
    for (ans = 0, f = 0, int i = 1; i <= w; i++) {
        // read an element of array 'a'
        k = getint(buf, pos);

        // check if the current element is zero
        if (k == 0) {
            f |= 1; // set flag 'f' if there is an element with zero value
            continue;
        }

        // if the current element is negative, update the 'close' variable
        // and set flag 'f' to -2 if all elements are negative
        if (k < 0) {
            if (f < 0 || close - (i - f) > -k) close = -k, f = i;
            if (f < 0) f = -2;
        }

        // update the 'ans' variable
        ans += k;
    }

    // check if the sum of all positive elements is zero or if flag 'f' is 1
    if (ans == 0 || !(f & 1)) {
        std::cout << "0\n"; // print 0 if the condition is true
        return 0;
    }

    // if all elements are not negative, calculate the minimum number of steps to reach from the start or end
    if (!(f & 2)) {
        std::cout << ans << "\n"; // print the answer
        return 0;
    }

    // initialize variables for the second loop
    for (close = 0, f = w, int i = w; i >= 1; i--) {
        // read an element of array 'a'
        if (a[i] == 0) {
            close = INF;
            f = -1;
            continue;
        }

        if (a[i] < 0) {
            // if the current element is negative, update the 'close' variable
            // and set flag 'f' to the index of the current element
            if (f < 0 || close - (f - i) > -a[i]) close = -a[i], f = i;
        } else {
            // if the current element is positive, update the 'b' array
            b[i] = INF;
            if (f >= 0) {
                int k = close - (f - i); // calculate the minimum number of steps to reach from the start to the current index
                if (k < 0) k = 0; // if the number is negative, set it to zero
                b[i] = k; // update the 'b' array
            }
        }
    }

    // initialize variables for the third loop
    for (close = 0, f = w, int i = 1; i <= w; i++) {
        // read an element of array 'a'
        if (a[i] > 0) {
            // if the current element is positive, update the 'ans' variable
            if (b[i] > a[i]) ans += a[i];
            else             ans += b[i];
        }
    }

    // print the answer
    std::cout << ans << "\n";
    return 0;
}

// <END-OF-CODE>
