
#include <iostream>

int main(void)
{
	int a, b, c, i, count;
	std::cin >> a >> b >> c;
	count = 0;
	for (i = a; i <= b; i++ ){
		if (c % i == 0)
			count++;
	}
	std::cout << count << std::endl;
	
	return 0;
}
