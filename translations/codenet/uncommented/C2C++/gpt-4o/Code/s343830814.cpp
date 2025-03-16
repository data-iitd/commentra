#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    char buf[512];
    std::cin.getline(buf, sizeof(buf));
    int len = std::strlen(buf);
    std::cout << buf[0] << (len - 3) << buf[len - 2] << std::endl;
    return 0;
}

// <END-OF-CODE>
