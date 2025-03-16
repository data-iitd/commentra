
#include <iostream>
#include <string>


int main()
{
    std::string inputNumbers;
    std::string temp;
    int a, b, c, d;
    int sum;
    std::string symbols;
    
    std::cin >> inputNumbers;

    temp = inputNumbers.substr(0, 1);
    a = std::stoi(temp);
    temp = inputNumbers.substr(1, 1);
    b = std::stoi(temp);
    temp = inputNumbers.substr(2, 1);
    c = std::stoi(temp);
    temp = inputNumbers.substr(3, 1);
    d = std::stoi(temp);
    
    for (int i = 0; i < 2; i++)
    {
	for (int j = 0; j < 2; j++)
	{
	    for (int k = 0; k < 2; k++)
	    {
		if (i == 0)
		{
		    sum = a + b;
		    symbols = "+";
		}
		else
		{
		    sum = a - b;
		    symbols = "-";
		}

		if (j == 0)
		{
		    sum = sum + c;
		    symbols = symbols + "+";
		}
		else
		{
		    sum = sum - c;
		    symbols = symbols + "-";
		}

		if (k == 0)
		{
		    sum = sum + d;
		    symbols = symbols + "+";
		}
		else
		{
		    sum = sum - d;
		    symbols = symbols + "-";
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


