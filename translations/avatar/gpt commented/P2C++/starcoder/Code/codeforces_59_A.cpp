#include <iostream>
#include <string>

int main()
{
    std::string txt;
    std::cout << "Enter text: ";
    std::getline(std::cin, txt);

    int cu = 0, cl = 0;
    for (auto z : txt)
    {
        if (std::islower(z))
            cl++;
        else
            cu++;
    }

    if (cu > cl)
        std::cout << txt.upper() << std::endl;
    else
        std::cout << txt.lower() << std::endl;

    return 0;
}

