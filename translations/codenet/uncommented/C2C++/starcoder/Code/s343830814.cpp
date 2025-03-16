#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string buf;
    std::getline(std::cin, buf);
    std::cout << buf[0] << buf.size()-3 << buf[buf.size()-2] << std::endl;
    return 0;
}

