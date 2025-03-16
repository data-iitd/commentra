#include <iostream>
#include <string>

int main()
{
    std::string mes;
    std::cin >> mes;
    std::cout << mes[0] << mes.length() - 2 << mes[mes.length() - 1] << std::endl;

    return 0;
}
