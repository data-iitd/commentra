#include <iostream>

int main(){
    int in;
    int h, m, s;
    std::cin >> in;

    h = in / 3600;
    in %= 3600;

    m = in / 60;
    in %= 60;

    s = in;

    std::cout << h << ":" << m << ":" << s << std::endl;
}

