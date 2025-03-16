#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::string inputNumbers;
    std::string temp;
    int a, b, c, d;
    int sum;
    char symbols[3];
    
    std::cin >> inputNumbers;

    temp = inputNumbers.substr(0, 1);
    a = std::atoi(temp.c_str());
    temp = inputNumbers.substr(1, 1);
    b = std::atoi(temp.c_str());
    temp = inputNumbers.substr(2, 1);
    c = std::atoi(temp.c_str());
    temp = inputNumbers.substr(3, 1);
    d = std::atoi(temp.c_str());
    
    for (int i = 0; i < 2; i++)
    {
	for (int j = 0; j < 2; j++)
	{
	    for (int k = 0; k < 2; k++)
	    {
		if (i == 0)
		{
		    sum = a + b;
		    symbols[0] = '+';
		}
		else
		{
		    sum = a - b;
		    symbols[0] = '-';
		}

		if (j == 0)
		{
		    sum = sum + c;
		    symbols[1] = '+';
		}
		else
		{
		    sum = sum - c;
		    symbols[1] = '-';
		}

		if (k == 0)
		{
		    sum = sum + d;
		    symbols[2] = '+';
		}
		else
		{
		    sum = sum - d;
		    symbols[2] = '-';
		}

		if (sum == 7)
		{
		    std::cout << a << symbols[0] << b << symbols[1] << c << symbols[2] << d << "=7" << std::endl;
		    
		    return 0;
		}
	    }
	}
    }

    return 0;
}
