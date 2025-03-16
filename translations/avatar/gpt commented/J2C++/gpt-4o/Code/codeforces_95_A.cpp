#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Main {
public:
    // Constructor for the Main class
    Main() {}

    // Method to compare two character arrays with case insensitivity
    int compare(const std::string& aa, int i, const std::string& bb, int j, int m) {
        while (m-- > 0) {
            // Convert characters to uppercase for comparison
            char a = std::toupper(aa[i]);
            char b = std::toupper(bb[j]);
            // Return the difference if characters do not match
            if (a != b) return a - b;
            i++;
            j++;
        }
        // Return 0 if all characters match
        return 0;
    }

    void main() {
        // Read the number of strings
        int n;
        std::cin >> n;
        std::vector<std::string> ss(n);

        // Read each string
        for (int i = 0; i < n; i++)
            std::cin >> ss[i];

        // Read the character array to be modified
        std::string cc;
        std::cin >> cc;
        int m = cc.length();

        // Read the character to be replaced
        char c;
        std::cin >> c;
        char c_ = std::toupper(c);

        // Determine the character to replace with
        char a = (c == 'a') ? 'b' : 'a';
        char a_ = std::toupper(a);

        // Vector to track positions that can be marked as lucky
        std::vector<bool> lucky(m, false);

        // Loop through each position in the character array
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++) {
                int l = ss[i].length();
                // Check if the substring matches and mark lucky positions
                if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0)
                    for (int h = 0; h < l; h++)
                        lucky[j + h] = true;
            }

        // Replace characters in the original array based on lucky positions
        for (int j = 0; j < m; j++)
            if (lucky[j]) {
                // Replace with the determined character based on case
                if (std::tolower(cc[j]) == c)
                    cc[j] = std::isupper(cc[j]) ? a_ : a;
                else
                    cc[j] = std::isupper(cc[j]) ? c_ : c;
            }

        // Print the modified character array
        std::cout << cc << std::endl;
    }
};

int main() {
    Main o;
    o.main();
    return 0;
}

// <END-OF-CODE>
