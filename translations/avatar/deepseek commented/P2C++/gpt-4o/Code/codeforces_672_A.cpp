#include <iostream>
#include <vector>

int main() {
    std::vector<int> li;
    int ind = 0;

    for (int i = 1; i < 371; i++) {
        std::vector<int> temp;
        int p = i, q = i;
        int count = 0;

        // Count the number of digits in i
        while (p != 0) {
            p /= 10;
            count++;
        }

        if (count == 1) {
            li.push_back(i);
        }

        if (count == 2) {
            temp.clear();
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            // Append reversed digits to li
            for (int j = temp.size() - 1; j >= 0; j--) {
                li.push_back(temp[j]);
            }
        }

        if (count == 3) {
            temp.clear();
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            // Append reversed digits to li
            for (int j = temp.size() - 1; j >= 0; j--) {
                li.push_back(temp[j]);
            }
        }
    }

    // Remove the last two elements from li
    li.pop_back();
    li.pop_back();

    int n;
    std::cin >> n; // Take an integer input from the user

    std::cout << li[n - 1] << std::endl; // Print the nth element of li based on the user's input

    return 0;
}
// <END-OF-CODE>
