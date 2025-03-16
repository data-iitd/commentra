
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <limits>
#include <tuple>
#include <functional>
#include <numeric>
#include <bitset>
#include <cmath>

using namespace std;

template <class T>
void print(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " \n"[i + 1 == v.size()];
    }
}

template <class T>
void print(set<T> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " \n";
    }
}

template <class T>
void print(unordered_set<T> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " \n";
    }
}

template <class T>
void print(map<T, int> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}

template <class T>
void print(unordered_map<T, int> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}

template <class T>
void print(vector<vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " \n"[j + 1 == v[i].size()];
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<T>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                cout << v[i][j][k] << " \n"[k + 1 == v[i][j].size()];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<T>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    cout << v[i][j][k][l] << " \n"[l + 1 == v[i][j][k].size()];
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<T>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        cout << v[i][j][k][l][m] << " \n"[m + 1 == v[i][j][k][l].size()];
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<T>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            cout << v[i][j][k][l][m][n] << " \n"[n + 1 == v[i][j][k][l][m].size()];
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<vector<T>>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) {
                                cout << v[i][j][k][l][m][n][o] << " \n"[o + 1 == v[i][j][k][l][m][n].size()];
                            }
                            cout << "\n";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<vector<vector<T>>>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) {
                                for (int p = 0; p < v[i][j][k][l][m][n][o].size(); p++) {
                                    cout << v[i][j][k][l][m][n][o][p] << " \n"[p + 1 == v[i][j][k][l][m][n][o].size()];
                                }
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<vector<vector<T>>>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) {
                                for (int p = 0; p < v[i][j][k][l][m][n][o].size(); p++) {
                                    for (int q = 0; q < v[i][j][k][l][m][n][o][p].size(); q++) {
                                        cout << v[i][j][k][l][m][n][o][p][q] << " \n"[q + 1 == v[i][j][k][l][m][n][o][p].size()];
                                    }
                                    cout << "\n";
                                }
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<vector<vector<vector<T>>>>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) {
                                for (int p = 0; p < v[i][j][k][l][m][n][o].size(); p++) {
                                    for (int q = 0; q < v[i][j][k][l][m][n][o][p].size(); q++) {
                                        for (int r = 0; r < v[i][j][k][l][m][n][o][p][q].size(); r++) {
                                            cout << v[i][j][k][l][m][n][o][p][q][r] << " \n"[r + 1 == v[i][j][k][l][m][n][o][p][q].size()];
                                        }
                                        cout << "\n";
                                    }
                                    cout << "\n";
                                }
                                cout << "\n";
                            }
                            cout << "\n";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

template <class T>
void print(vector<vector<vector<vector<vector<vector<vector<vector<vector<T>>>>>>>>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                for (int l = 0; l < v[i][j][k].size(); l++) {
                    for (int m = 0; m < v[i][j][k][l].size(); m++) {
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) {
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) {
                                for (int p = 0; p < v[i][j][k][l][m][n][o].size(); p++) {
                                    for (int q = 0; q < v[i][j][k][l][m][n][o][p].size(); q++) {
                                        for (int r = 0; r < v[i][j][k][l][m][n][o][p][q].size(); r++) {
                                            for (int s = 0; s < v[i][j][k][l][m][n][o][p][q][r].size(); s++) {
                                                cout << v[i][j][k][l][m][n][o][p][q][r][s] << " \n"[s + 1 == v[i][j][k][l][m][n][o][p][q][r].size()];
                                            }
                                            cout << "\n";
                                        }
                                        cout << "\n";
                                    }
                          