
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <vector> 
#include <set> 
#include <map> 
#include <unordered_set> 
#include <unordered_map> 
#include <queue> 
#include <ctime> 
#include <cassert> 
#include <complex> 
#include <string> 
#include <cctype> 
#include <fstream> 
#include <sstream> 
#include <iomanip> 
#include <numeric> 
#include <array> 
#include <bitset> 
#include <list> 
#include <forward_list> 
#include <deque> 
#include <stack> 
#include <functional> 
#include <iterator> 
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl 
#define print(x) std::cout << (x) << std::endl 
#define println(x) std::cout << (x) << " " << std::endl 
#define printint(x) std::cout << (x) << " " 
#define printvec(v) printvec((v), (#v)) 
template<class T> void printvec(std::vector<T> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << v[i] << " "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printmat(m) printmat((m), (#m)) 
template<class T> void printmat(std::vector<std::vector<T>> m, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < m.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < m[i].size(); j++) { 
            std::cout << m[i][j] << " "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printmat2(m) printmat2((m), (#m)) 
template<class T> void printmat2(std::vector<std::vector<T>> m, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < m.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < m[i].size(); j++) { 
            std::cout << m[i][j] << " "; 
        } 
        std::cout << "]" << std::endl; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printset(s) printset((s), (#s)) 
template<class T> void printset(std::set<T> s, std::string name) { 
    std::cout << name << " = ["; 
    for (auto it = s.begin(); it != s.end(); it++) { 
        std::cout << *it << " "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printmap(m) printmap((m), (#m)) 
template<class T, class U> void printmap(std::map<T, U> m, std::string name) { 
    std::cout << name << " = ["; 
    for (auto it = m.begin(); it != m.end(); it++) { 
        std::cout << it->first << " " << it->second << " "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printpair(p) printpair((p), (#p)) 
template<class T, class U> void printpair(std::pair<T, U> p, std::string name) { 
    std::cout << name << " = (" << p.first << ", " << p.second << ")" << std::endl; 
} 
#define printvecvec(v) printvecvec((v), (#v)) 
template<class T> void printvecvec(std::vector<std::vector<T>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << v[i][j] << " "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvec(v) printvecvecvec((v), (#v)) 
template<class T> void printvecvecvec(std::vector<std::vector<std::vector<T>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << v[i][j][k] << " "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvec(v) printvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvec(std::vector<std::vector<std::vector<std::vector<T>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << "["; 
                for (int l = 0; l < v[i][j][k].size(); l++) { 
                    std::cout << v[i][j][k][l] << " "; 
                } 
                std::cout << "] "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvecvec(v) printvecvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvecvec(std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << "["; 
                for (int l = 0; l < v[i][j][k].size(); l++) { 
                    std::cout << "["; 
                    for (int m = 0; m < v[i][j][k][l].size(); m++) { 
                        std::cout << v[i][j][k][l][m] << " "; 
                    } 
                    std::cout << "] "; 
                } 
                std::cout << "] "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvecvecvec(v) printvecvecvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvecvecvec(std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << "["; 
                for (int l = 0; l < v[i][j][k].size(); l++) { 
                    std::cout << "["; 
                    for (int m = 0; m < v[i][j][k][l].size(); m++) { 
                        std::cout << "["; 
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) { 
                            std::cout << v[i][j][k][l][m][n] << " "; 
                        } 
                        std::cout << "] "; 
                    } 
                    std::cout << "] "; 
                } 
                std::cout << "] "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvecvecvecvec(v) printvecvecvecvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvecvecvecvec(std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << "["; 
                for (int l = 0; l < v[i][j][k].size(); l++) { 
                    std::cout << "["; 
                    for (int m = 0; m < v[i][j][k][l].size(); m++) { 
                        std::cout << "["; 
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) { 
                            std::cout << "["; 
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) { 
                                std::cout << v[i][j][k][l][m][n][o] << " "; 
                            } 
                            std::cout << "] "; 
                        } 
                        std::cout << "] "; 
                    } 
                    std::cout << "] "; 
                } 
                std::cout << "] "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvecvecvecvecvec(v) printvecvecvecvecvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvecvecvecvecvec(std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for (int i = 0; i < v.size(); i++) { 
        std::cout << "["; 
        for (int j = 0; j < v[i].size(); j++) { 
            std::cout << "["; 
            for (int k = 0; k < v[i][j].size(); k++) { 
                std::cout << "["; 
                for (int l = 0; l < v[i][j][k].size(); l++) { 
                    std::cout << "["; 
                    for (int m = 0; m < v[i][j][k][l].size(); m++) { 
                        std::cout << "["; 
                        for (int n = 0; n < v[i][j][k][l][m].size(); n++) { 
                            std::cout << "["; 
                            for (int o = 0; o < v[i][j][k][l][m][n].size(); o++) { 
                                std::cout << "["; 
                                for (int p = 0; p < v[i][j][k][l][m][n][o].size(); p++) { 
                                    std::cout << v[i][j][k][l][m][n][o][p] << " "; 
                                } 
                                std::cout << "] "; 
                            } 
                            std::cout << "] "; 
                        } 
                        std::cout << "] "; 
                    } 
                    std::cout << "] "; 
                } 
                std::cout << "] "; 
            } 
            std::cout << "] "; 
        } 
        std::cout << "] "; 
    } 
    std::cout << "]" << std::endl; 
} 
#define printvecvecvecvecvecvecvecvecvec(v) printvecvecvecvecvecvecvecvecvec((v), (#v)) 
template<class T> void printvecvecvecvecvecvecvecvecvec(std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>>>>>> v, std::string name) { 
    std::cout << name << " = ["; 
    for 