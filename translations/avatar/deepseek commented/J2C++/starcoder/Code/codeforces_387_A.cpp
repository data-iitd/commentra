
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

int main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    string s, t;
    getline(cin, s, ':');
    getline(cin, t, ':');
    vector<string> s_vec, t_vec;
    istringstream iss(s);
    for (string token; iss >> token;) {
        s_vec.push_back(token);
    }
    istringstream ist(t);
    for (string token; ist >> token;) {
        t_vec.push_back(token);
    }
    int s_hour = stoi(s_vec[0]);
    int s_min = stoi(s_vec[1]);
    int t_hour = stoi(t_vec[0]);
    int t_min = stoi(t_vec[1]);
    auto s_time = chrono::hours(s_hour) + chrono::minutes(s_min);
    auto t_time = chrono::hours(t_hour) + chrono::minutes(t_min);

    // Step 2: Calculate the difference between the two times
    auto diff = s_time - t_time;
    cout << diff.count() << endl;
}

