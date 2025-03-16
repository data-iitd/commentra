#include <iostream>
#include <cstdlib>

int main()
{
    char inputNumbers[5];
    char temp[2];
    int a, b, c, d;
    int sum;
    char symbols[3];

    std::cin >> inputNumbers;

    temp[1] = '\0';

    temp[0] = inputNumbers[0];
    a = atoi(temp);
    temp[0] = inputNumbers[1];
    b = atoi(temp);
    temp[0] = inputNumbers[2];
    c = atoi(temp);
    temp[0] = inputNumbers[3];
    d = atoi(temp);
    
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

// <END-OF-CODE>
