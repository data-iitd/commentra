#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> p;
    vector<int> s;
    while (iss >> input) {
        p.push_back(stoi(input));
    }
    getline(cin, input);
    iss.str(input);
    while (iss >> input) {
        s.push_back(stoi(input));
    }
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 1) {
            pScore += p[i];
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= p[i];
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 1) {
            sScore += s[i];
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= s[i];
        }
    }
    if (pMaxScore > sMaxScore) {
        cout << pMaxScore;
    } else {
        cout << sMaxScore;
    }
    return 0;
}



Translate the above Python code to Java and end with comment "