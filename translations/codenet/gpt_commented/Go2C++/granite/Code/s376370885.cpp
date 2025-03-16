
// by syu
#include <bits/stdc++.h>
using namespace std;

// Initialize a new Scanner for reading input from standard input (cin)
class Scanner {
public:
    Scanner(std::istream& in = std::cin, int buf_size = 0) : buf_size(buf_size), buf(buf_size) {
        s.buf(&buf[0], buf_size);
        s.sync_with_stdio(false);
    }

    string next() {
        s.get();
        s.getline(&buf[0], buf_size,'');
        return buf;
    }

    int nextInt() {
        int x;
        s >> x;
        return x;
    }

private:
    int buf_size;
    string buf;
    std::istream& s;
};

int main() {
    Scanner in;
    int n = in.nextInt();
    int k = in.nextInt();
    cout << (n % k == 0? 0 : 1) << endl; // Print 0 if n is divisible by k, otherwise print 1
}

// Pln is a convenience function to print a line to standard output
void Pln(const vector<string>& s) {
    for (const auto& str : s) {
        cout << str << endl;
    }
}

// Pln is a convenience function to print a line to standard output
void Pln(const vector<int>& s) {
    for (const auto& num : s) {
        cout << num << endl;
    }
}

// Pln is a convenience function to print a line to standard output
void Pln(const vector<vector<int>>& s) {
    for (const auto& vec : s) {
        for (const auto& num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Pln is a convenience function to print a line to standard output
void Pln(const string& s) {
    cout << s << endl;
}

// Pln is a convenience function to print a line to standard output
void Pln(const char* s) {
    cout << s << endl;
}

// Pln is a convenience function to print a line to standard output
void Pln(int x) {
    cout << x << endl;
}

// Pln is a convenience function to print a line to standard output
void Pln() {
    cout << endl;
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list<string>& s) {
    Pln(vector<string>(s));
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list<int>& s) {
    Pln(vector<int>(s));
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list<vector<int>>& s) {
    Pln(vector<vector<int>>(s));
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list<int>>& s) {
    vector<vector<int>> v;
    for (const auto& inner : s) {
        v.push_back(vector<int>(inner));
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list<int>>>& s) {
    vector<vector<vector<int>>> v;
    for (const auto& middle : s) {
        vector<vector<int>> inner;
        for (const auto& inner_ : middle) {
            inner.push_back(vector<int>(inner_));
        }
        v.push_back(inner);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list<int>>>>& s) {
    vector<vector<vector<vector<int>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<int>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<int>> inner;
            for (const auto& inner_ : middle_) {
                inner.push_back(vector<int>(inner_));
            }
            middle.push_back(inner);
        }
        v.push_back(middle);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list< initializer_list<int>>>>>& s) {
    vector<vector<vector<vector<vector<int>>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<vector<int>>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<vector<int>>> inner;
            for (const auto& inner_ : middle_) {
                vector<vector<int>> inner__;
                for (const auto& inner__ : inner_) {
                    inner__.push_back(vector<int>(inner__));
                }
                inner.push_back(inner__);
            }
            middle.push_back(inner);
        }
        v.push_back(middle);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list<int>>>>>>>& s) {
    vector<vector<vector<vector<vector<vector<int>>>>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<vector<vector<int>>>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<vector<vector<int>>>> inner;
            for (const auto& inner_ : middle_) {
                vector<vector<vector<int>>> inner__;
                for (const auto& inner__ : inner_) {
                    vector<vector<int>> inner___;
                    for (const auto& inner___ : inner__) {
                        inner___.push_back(vector<int>(inner___));
                    }
                    inner__.push_back(inner___);
                }
                inner.push_back(inner__);
            }
            middle.push_back(inner);
        }
        v.push_back(middle);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list<int>>>>>>>>& s) {
    vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<vector<vector<vector<int>>>>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<vector<vector<vector<int>>>>> inner;
            for (const auto& inner_ : middle_) {
                vector<vector<vector<vector<int>>>> inner__;
                for (const auto& inner__ : inner_) {
                    vector<vector<vector<int>>> inner___;
                    for (const auto& inner___ : inner__) {
                        vector<vector<int>> inner____;
                        for (const auto& inner____ : inner___) {
                            inner_____.push_back(vector<int>(inner____));
                        }
                        inner___.push_back(inner____);
                    }
                    inner__.push_back(inner___);
                }
                inner.push_back(inner__);
            }
            middle.push_back(inner);
        }
        v.push_back(middle);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list<int>>>>>>>>> s) {
    vector<vector<vector<vector<vector<vector<vector<int>>>>>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>> inner;
            for (const auto& inner_ : middle_) {
                vector<vector<vector<vector<vector<vector<int>>>>>>>>> inner__;
                for (const auto& inner__ : inner_) {
                    vector<vector<vector<vector<vector<int>>>>>>> inner___;
                    for (const auto& inner___ : inner__) {
                        vector<vector<vector<vector<int>>>>>> inner____;
                        for (const auto& inner____ : inner___) {
                            vector<vector<vector<int>>> inner_____;
                            for (const auto& inner_____ : inner____) {
                                inner_______.push_back(vector<int>(inner_____));
                            }
                            inner_____.push_back(inner_____);
                        }
                        inner___.push_back(inner____);
                    }
                    inner__.push_back(inner___);
                }
                inner.push_back(inner__);
            }
            middle.push_back(inner);
        }
        v.push_back(middle);
    }
    Pln(v);
}

// Pln is a convenience function to print a line to standard output
void Pln(const initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list< initializer_list<int>>>>>>>>>>> s) {
    vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> v;
    for (const auto& outter : s) {
        vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> middle;
        for (const auto& middle_ : outter) {
            vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> inner;
            for (const auto& inner_ : middle_) {
                vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> inner__;
                for (const auto& inner__ : inner_) {
                    vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> inner___;
                    for (const auto& inner___ : inner__) {
                        vector<vector<vector<vector<vector<int>>>>>>>>> inner____;
                        for (const auto& inner____ : inner___) {
                            vector<vector<vector<vector<int>>>>>>>>> inner_____;
                            for (const auto& inner_____ : inner____) {
                                vector<vector<vector<int>>> inner_______;
                                for (const auto& inner______ : inner_____) {
                                    inner_________.push_back(vector<int>(inner_______));
                                }
                                inner_____.push_back(inner_________);
                            }
                            inner___.push_back(inner____);
                        }
                        inner__.push_back(inner___);