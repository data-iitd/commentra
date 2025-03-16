#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string buf;
    std::getline(std::cin, buf);
    int len = buf.length();
    std::cout << buf[0] << len-3 << buf[len-2] << std::endl;
    return 0;
}

