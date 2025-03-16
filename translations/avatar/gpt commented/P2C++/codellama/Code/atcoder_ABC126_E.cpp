#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to read input from standard input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read input from standard input
int input_int() {
    int n;
    cin >> n;
    return n;
}

// Function to read input from standard input
vector<int> input_int_vector() {
    string s = input();
    vector<int> v;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            v.push_back(s[i] - '0');
        }
    }
    
    return v;
}

// Function to read input from standard input
vector<vector<int>> input_int_matrix() {
    string s = input();
    vector<vector<int>> m;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\n') {
            m.push_back(input_int_vector());
        }
    }
    
    return m;
}

// Function to print output to standard output
void print(int n) {
    cout << n << endl;
}

// Function to print output to standard output
void print(string s) {
    cout << s << endl;
}

// Function to print output to standard output
void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

// Function to print output to standard output
void print(vector<vector<int>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << m[i][j];
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<string>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << m[i][j];
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<int>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                if (k != 0) {
                    cout << " ";
                }
                cout << m[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<string>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                if (k != 0) {
                    cout << " ";
                }
                cout << m[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<int>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    if (l != 0) {
                        cout << " ";
                    }
                    cout << m[i][j][k][l];
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<string>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    if (l != 0) {
                        cout << " ";
                    }
                    cout << m[i][j][k][l];
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<int>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        if (m != 0) {
                            cout << " ";
                        }
                        cout << m[i][j][k][l][m];
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<string>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        if (m != 0) {
                            cout << " ";
                        }
                        cout << m[i][j][k][l][m];
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<vector<int>>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        for (int n = 0; n < m[i][j][k][l][m].size(); n++) {
                            if (n != 0) {
                                cout << " ";
                            }
                            cout << m[i][j][k][l][m][n];
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<vector<string>>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        for (int n = 0; n < m[i][j][k][l][m].size(); n++) {
                            if (n != 0) {
                                cout << " ";
                            }
                            cout << m[i][j][k][l][m][n];
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<vector<vector<int>>>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        for (int n = 0; n < m[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < m[i][j][k][l][m][n].size(); o++) {
                                if (o != 0) {
                                    cout << " ";
                                }
                                cout << m[i][j][k][l][m][n][o];
                            }
                            cout << endl;
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<vector<vector<string>>>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        for (int n = 0; n < m[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < m[i][j][k][l][m][n].size(); o++) {
                                if (o != 0) {
                                    cout << " ";
                                }
                                cout << m[i][j][k][l][m][n][o];
                            }
                            cout << endl;
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to print output to standard output
void print(vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            for (int k = 0; k < m[i][j].size(); k++) {
                for (int l = 0; l < m[i][j][k].size(); l++) {
                    for (int m = 0; m < m[i][j][k][l].size(); m++) {
                        for (int n = 0; n < m[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < m[i][j][k][l][m][n].size(); o++) {
                                for (int p = 0; p < m[i][j][k][l][m][n][o].size(); p++) {
                                    if (p != 0) {
          