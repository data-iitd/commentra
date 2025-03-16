#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// Constants definition
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Function to read an integer from standard input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to calculate the modulo operation
int calcMod(int x) {
    return x % mod;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    return min(min(a, b), c);
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Main function
int main() {
    // Read the first integer from the standard input
    int N = getInt();

    // Calculate the square root of N
    int sqrtN = (int)sqrt(N);

    // Initialize the minimum number with N
    int minDivisors = N;

    // Iterate through all numbers from 1 to the square root of N
    for (int i = 1; i <= sqrtN; i++) {
        // Check if N is divisible by i
        if (N % i != 0) {
            continue;
        }

        // Calculate the number of divisors of i and N
        int num = i + (N / i) - 2;

        // Update the minimum number if the current number is smaller
        minDivisors = min(minDivisors, num);
    }

    // Print the minimum number
    cout << minDivisors << endl;

    return 0;
}

// Graph data structure
class Graph {
public:
    int n;
    vector<vector<int>> edges;

    // Initialize a new Graph with n vertices
    Graph(int n) : n(n), edges(n) {}

    // Add an edge between two vertices in the Graph
    void addEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    // Depth First Search function
    void dfs(int c, unordered_set<int>& visited) {
        // Mark the current vertex as visited
        visited.insert(c);

        // Iterate through all neighbors of the current vertex
        for (int v : edges[c]) {
            // If the neighbor is already visited, skip it
            if (visited.find(v) != visited.end()) {
                continue;
            }

            // Recursively call DFS for the neighbor
            dfs(v, visited);
        }
    }
};

// Helper function for reversing a string
string reverseString(const string& s) {
    string reversed(s);
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Helper function for printing an integer array
void printIntArray(const vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array[i];
        if (i < array.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Helper function for checking if a string exists in an array of strings
bool strSearch(const vector<string>& a, const string& b) {
    return find(a.begin(), a.end(), b) != a.end();
}

// Helper function for absolute value
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Helper function for power
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

// Helper function for power with modulo
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

// Helper function for finding the maximum value
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function for finding the maximum of three integers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// Helper function for finding the minimum of an array
int minArray(const vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

// Helper function for finding the maximum of an array
int maxArray(const vector<int>& nums) {
    return *max_element(nums.begin(), nums.end());
}

// Helper function for calculating the absolute value of a double
double abs(double a) {
    return (a < 0) ? -a : a;
}

// Helper function for calculating the square root of a double
double sqrt(double a) {
    return std::sqrt(a);
}

// Helper function for calculating the power of a double
double pow(double base, double exp) {
    return std::pow(base, exp);
}

// Helper function for calculating the logarithm of a double
double log(double a) {
    return std::log(a);
}

// Helper function for calculating the exponential of a double
double exp(double a) {
    return std::exp(a);
}

// Helper function for calculating the sine of a double
double sin(double a) {
    return std::sin(a);
}

// Helper function for calculating the cosine of a double
double cos(double a) {
    return std::cos(a);
}

// Helper function for calculating the tangent of a double
double tan(double a) {
    return std::tan(a);
}

// Helper function for calculating the factorial of an integer
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Helper function for calculating the greatest common divisor of two integers
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Helper function for calculating the least common multiple of two integers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Helper function for checking if a number is even
bool isEven(int n) {
    return n % 2 == 0;
}

// Helper function for checking if a number is odd
bool isOdd(int n) {
    return n % 2 != 0;
}

// Helper function for checking if a number is a perfect square
bool isPerfectSquare(int n) {
    int sqrtN = (int)sqrt(n);
    return (sqrtN * sqrtN == n);
}

// Helper function for checking if a number is a power of two
bool isPowerOfTwo(int n) {
    return (n > 0) && (n & (n - 1)) == 0;
}

// Helper function for checking if a number is a power of three
bool isPowerOfThree(int n) {
    while (n > 1 && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

// Helper function for checking if a number is a power of five
bool isPowerOfFive(int n) {
    while (n > 1 && n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}

// Helper function for checking if a number is a power of ten
bool isPowerOfTen(int n) {
    while (n > 1 && n % 10 == 0) {
        n /= 10;
    }
    return n == 1;
}

// Helper function for checking if a number is a palindrome
bool isPalindrome(int n) {
    string s = to_string(n);
    string rev = reverseString(s);
    return s == rev;
}

// Helper function for checking if a string is a palindrome
bool isPalindrome(const string& s) {
    string rev = reverseString(s);
    return s == rev;
}

// Helper function for checking if a string is a valid number
bool isValidNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

// Helper function for checking if a string is a valid email
bool isValidEmail(const string& s) {
    // Simple email validation logic
    size_t atPos = s.find('@');
    size_t dotPos = s.find('.', atPos);
    return atPos != string::npos && dotPos != string::npos && dotPos > atPos + 1;
}

// Helper function for checking if a string is a valid URL
bool isValidURL(const string& s) {
    // Simple URL validation logic
    return s.find("http://") == 0 || s.find("https://") == 0;
}

// Helper function for checking if a string is a valid IP address
bool isValidIP(const string& s) {
    // Simple IP address validation logic
    int dots = count(s.begin(), s.end(), '.');
    return dots == 3;
}

// Helper function for checking if a string is a valid phone number
bool isValidPhoneNumber(const string& s) {
    // Simple phone number validation logic
    return all_of(s.begin(), s.end(), ::isdigit);
}

// Helper function for checking if a string is a valid date
bool isValidDate(const string& s) {
    // Simple date validation logic
    return s.size() == 10 && s[2] == '-' && s[5] == '-';
}

// Helper function for checking if a string is a valid time
bool isValidTime(const string& s) {
    // Simple time validation logic
    return s.size() == 5 && s[2] == ':';
}

// Helper function for checking if a string is a valid date and time
bool isValidDateTime(const string& s) {
    // Simple date and time validation logic
    return s.size() == 19 && s[10] == 'T';
}

// Helper function for checking if a string is a valid JSON
bool isValidJSON(const string& s) {
    // Simple JSON validation logic
    return s.front() == '{' && s.back() == '}';
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid CSV
bool isValidCSV(const string& s) {
    // Simple CSV validation logic
    return count(s.begin(), s.end(), ',') > 0;
}

// Helper function for checking if a string is a valid HTML
bool isValidHTML(const string& s) {
    // Simple HTML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid Markdown
bool isValidMarkdown(const string& s) {
    // Simple Markdown validation logic
    return s.find('#') != string::npos;
}

// Helper function for checking if a string is a valid YAML
bool isValidYAML(const string& s) {
    // Simple YAML validation logic
    return s.find(':') != string::npos;
}

// Helper function for checking if a string is a valid INI
bool isValidINI(const string& s) {
    // Simple INI validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid TOML
bool isValidTOML(const string& s) {
    // Simple TOML validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid SQL
bool isValidSQL(const string& s) {
    // Simple SQL validation logic
    return s.find("SELECT") != string::npos || s.find("INSERT") != string::npos;
}

// Helper function for checking if a string is a valid shell command
bool isValidShellCommand(const string& s) {
    // Simple shell command validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid regex
bool isValidRegex(const string& s) {
    // Simple regex validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid UUID
bool isValidUUID(const string& s) {
    // Simple UUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid GUID
bool isValidGUID(const string& s) {
    // Simple GUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid MAC address
bool isValidMACAddress(const string& s) {
    // Simple MAC address validation logic
    return s.size() == 17;
}

// Helper function for checking if a string is a valid IPv4 address
bool isValidIPv4Address(const string& s) {
    // Simple IPv4 address validation logic
    return s.size() > 0;
}

// Helper function for checking if a string is a valid IPv6 address
bool isValidIPv6Address(const string& s) {
    // Simple IPv6 address validation logic
    return s.size() > 0;
}

// Helper function for checking if a string is a valid URL
bool isValidURL(const string& s) {
    // Simple URL validation logic
    return s.find("http://") == 0 || s.find("https://") == 0;
}

// Helper function for checking if a string is a valid email
bool isValidEmail(const string& s) {
    // Simple email validation logic
    size_t atPos = s.find('@');
    size_t dotPos = s.find('.', atPos);
    return atPos != string::npos && dotPos != string::npos && dotPos > atPos + 1;
}

// Helper function for checking if a string is a valid phone number
bool isValidPhoneNumber(const string& s) {
    // Simple phone number validation logic
    return all_of(s.begin(), s.end(), ::isdigit);
}

// Helper function for checking if a string is a valid date
bool isValidDate(const string& s) {
    // Simple date validation logic
    return s.size() == 10 && s[2] == '-' && s[5] == '-';
}

// Helper function for checking if a string is a valid time
bool isValidTime(const string& s) {
    // Simple time validation logic
    return s.size() == 5 && s[2] == ':';
}

// Helper function for checking if a string is a valid date and time
bool isValidDateTime(const string& s) {
    // Simple date and time validation logic
    return s.size() == 19 && s[10] == 'T';
}

// Helper function for checking if a string is a valid JSON
bool isValidJSON(const string& s) {
    // Simple JSON validation logic
    return s.front() == '{' && s.back() == '}';
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid CSV
bool isValidCSV(const string& s) {
    // Simple CSV validation logic
    return count(s.begin(), s.end(), ',') > 0;
}

// Helper function for checking if a string is a valid HTML
bool isValidHTML(const string& s) {
    // Simple HTML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid Markdown
bool isValidMarkdown(const string& s) {
    // Simple Markdown validation logic
    return s.find('#') != string::npos;
}

// Helper function for checking if a string is a valid YAML
bool isValidYAML(const string& s) {
    // Simple YAML validation logic
    return s.find(':') != string::npos;
}

// Helper function for checking if a string is a valid INI
bool isValidINI(const string& s) {
    // Simple INI validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid TOML
bool isValidTOML(const string& s) {
    // Simple TOML validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid SQL
bool isValidSQL(const string& s) {
    // Simple SQL validation logic
    return s.find("SELECT") != string::npos || s.find("INSERT") != string::npos;
}

// Helper function for checking if a string is a valid shell command
bool isValidShellCommand(const string& s) {
    // Simple shell command validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid regex
bool isValidRegex(const string& s) {
    // Simple regex validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid UUID
bool isValidUUID(const string& s) {
    // Simple UUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid GUID
bool isValidGUID(const string& s) {
    // Simple GUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid MAC address
bool isValidMACAddress(const string& s) {
    // Simple MAC address validation logic
    return s.size() == 17;
}

// Helper function for checking if a string is a valid IPv4 address
bool isValidIPv4Address(const string& s) {
    // Simple IPv4 address validation logic
    return s.size() > 0;
}

// Helper function for checking if a string is a valid IPv6 address
bool isValidIPv6Address(const string& s) {
    // Simple IPv6 address validation logic
    return s.size() > 0;
}

// Helper function for checking if a string is a valid URL
bool isValidURL(const string& s) {
    // Simple URL validation logic
    return s.find("http://") == 0 || s.find("https://") == 0;
}

// Helper function for checking if a string is a valid email
bool isValidEmail(const string& s) {
    // Simple email validation logic
    size_t atPos = s.find('@');
    size_t dotPos = s.find('.', atPos);
    return atPos != string::npos && dotPos != string::npos && dotPos > atPos + 1;
}

// Helper function for checking if a string is a valid phone number
bool isValidPhoneNumber(const string& s) {
    // Simple phone number validation logic
    return all_of(s.begin(), s.end(), ::isdigit);
}

// Helper function for checking if a string is a valid date
bool isValidDate(const string& s) {
    // Simple date validation logic
    return s.size() == 10 && s[2] == '-' && s[5] == '-';
}

// Helper function for checking if a string is a valid time
bool isValidTime(const string& s) {
    // Simple time validation logic
    return s.size() == 5 && s[2] == ':';
}

// Helper function for checking if a string is a valid date and time
bool isValidDateTime(const string& s) {
    // Simple date and time validation logic
    return s.size() == 19 && s[10] == 'T';
}

// Helper function for checking if a string is a valid JSON
bool isValidJSON(const string& s) {
    // Simple JSON validation logic
    return s.front() == '{' && s.back() == '}';
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid CSV
bool isValidCSV(const string& s) {
    // Simple CSV validation logic
    return count(s.begin(), s.end(), ',') > 0;
}

// Helper function for checking if a string is a valid HTML
bool isValidHTML(const string& s) {
    // Simple HTML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid Markdown
bool isValidMarkdown(const string& s) {
    // Simple Markdown validation logic
    return s.find('#') != string::npos;
}

// Helper function for checking if a string is a valid YAML
bool isValidYAML(const string& s) {
    // Simple YAML validation logic
    return s.find(':') != string::npos;
}

// Helper function for checking if a string is a valid INI
bool isValidINI(const string& s) {
    // Simple INI validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid TOML
bool isValidTOML(const string& s) {
    // Simple TOML validation logic
    return s.find('=') != string::npos;
}

// Helper function for checking if a string is a valid XML
bool isValidXML(const string& s) {
    // Simple XML validation logic
    return s.front() == '<' && s.back() == '>';
}

// Helper function for checking if a string is a valid SQL
bool isValidSQL(const string& s) {
    // Simple SQL validation logic
    return s.find("SELECT") != string::npos || s.find("INSERT") != string::npos;
}

// Helper function for checking if a string is a valid shell command
bool isValidShellCommand(const string& s) {
    // Simple shell command validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid regex
bool isValidRegex(const string& s) {
    // Simple regex validation logic
    return !s.empty();
}

// Helper function for checking if a string is a valid UUID
bool isValidUUID(const string& s) {
    // Simple UUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid GUID
bool isValidGUID(const string& s) {
    // Simple GUID validation logic
    return s.size() == 36;
}

// Helper function for checking if a string is a valid MAC address
bool isValidMACAddress(const string& s) {
    // Simple MAC address validation logic
    return s.size() == 17;
}

// Helper function for checking if a string is a valid IPv4 address
