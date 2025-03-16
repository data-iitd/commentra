#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <functional>

class Io {
public:
    Io() : reader(std::cin), writer(std::cout) {}
    void Flush() { writer.flush(); }
    std::string NextLine() { std::string line; std::getline(reader, line); return line; }
    std::string Next() {
        while (tokens.empty()) {
            std::string line;
            std::getline(reader, line);
            std::istringstream iss(line);
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
        }
        std::string token = tokens.front();
        tokens.pop_front();
        return token;
    }
    int Int() { return std::stoi(Next()); }
    double Float() { return std::stod(Next()); }
    void PrintLn(const std::vector<int>& a) {
        for (int x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::vector<std::string>& a) {
        for (const std::string& x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::vector<double>& a) {
        for (double x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::initializer_list<int>& a) {
        for (int x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::initializer_list<std::string>& a) {
        for (const std::string& x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::initializer_list<double>& a) {
        for (double x : a) {
            writer << x << " ";
        }
        writer << "\n";
    }
    void PrintLn(const std::vector<std::vector<int>>& a) {
        for (const auto& row : a) {
            for (int x : row) {
                writer << x << " ";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::string>>& a) {
        for (const auto& row : a) {
            for (const std::string& x : row) {
                writer << x << " ";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<double>>& a) {
        for (const auto& row : a) {
            for (double x : row) {
                writer << x << " ";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<int>>>& a) {
        for (const auto& matrix : a) {
            for (const auto& row : matrix) {
                for (int x : row) {
                    writer << x << " ";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::string>>>& a) {
        for (const auto& matrix : a) {
            for (const auto& row : matrix) {
                for (const std::string& x : row) {
                    writer << x << " ";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<double>>>& a) {
        for (const auto& matrix : a) {
            for (const auto& row : matrix) {
                for (double x : row) {
                    writer << x << " ";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<int>>>>& a) {
        for (const auto& cube : a) {
            for (const auto& matrix : cube) {
                for (const auto& row : matrix) {
                    for (int x : row) {
                        writer << x << " ";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::string>>>>& a) {
        for (const auto& cube : a) {
            for (const auto& matrix : cube) {
                for (const auto& row : matrix) {
                    for (const std::string& x : row) {
                        writer << x << " ";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<double>>>>& a) {
        for (const auto& cube : a) {
            for (const auto& matrix : cube) {
                for (const auto& row : matrix) {
                    for (double x : row) {
                        writer << x << " ";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (double x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (int x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::string>>>>>& a) {
        for (const auto& hyper : a) {
            for (const auto& cube : hyper) {
                for (const auto& matrix : cube) {
                    for (const auto& row : matrix) {
                        for (const std::string& x : row) {
                            writer << x << " ";
                        }
                        writer << "\n";
                    }
                    writer << "\n";
                }
                writer << "\n";
            }
            writer << "\n";
        }
    }
    void PrintLn(const std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector