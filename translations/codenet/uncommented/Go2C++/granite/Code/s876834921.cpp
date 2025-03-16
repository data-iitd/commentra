
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string::size_type pos = 0;
    while ((pos = s.find("dream", pos))!= std::string::npos) {
        s.replace(pos, 5, "D");
        pos += 1;
    }
    while ((pos = s.find("erase", pos))!= std::string::npos) {
        s.replace(pos, 5, "E");
        pos += 1;
    }
    while ((pos = s.find("Der", pos))!= std::string::npos) {
        s.erase(pos, 3);
        pos += 1;
    }
    while ((pos = s.find("Er", pos))!= std::string::npos) {
        s.erase(pos, 2);
        pos += 1;
    }
    while ((pos = s.find("D", pos))!= std::string::npos) {
        s.erase(pos, 1);
        pos += 1;
    }
    while ((pos = s.find("E", pos))!= std::string::npos) {
        s.erase(pos, 1);
        pos += 1;
    }
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

    if (s.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

