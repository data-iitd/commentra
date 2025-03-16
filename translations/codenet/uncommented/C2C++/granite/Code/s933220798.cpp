
#include <iostream>

int main(void)
{
	double a;
	double ave = 0;
	int i;
	
	for (i = 0; i < 5; i++){
		std::cin >> a;
		if (a <= 40){
			ave += 40;
		}
		else {
			ave += a;
		}
	}
	//printf("%.0f\n", ave);
	
	ave /= 5.0;
	
	std::cout << ave << std::endl;
	
	return (0);
}

