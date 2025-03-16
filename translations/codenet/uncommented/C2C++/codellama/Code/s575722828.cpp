#include <iostream>


int main()
{
int S;

std::cin >> S;


std::cout << (int)(S/3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << std::endl;

return 0;

}

