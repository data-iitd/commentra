
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    char buf[512];
    int len;
    std::cin.getline(buf, sizeof(buf));
    len = strlen(buf);
    std::cout << buf[0] << len-3 << buf[len-2] << std::endl;
    return 0;
}
