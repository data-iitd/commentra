#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
	string source = "";
	cin >> source;

	if(source.length() > 10 or source.length() < 1):
		return -1

	max_i = int(pow(2, source.length() - 1))

	sum = 0

	for i in range(max_i):
		plus = bitset(i)

		number = 0

		working = source
		while(plus.any()):
			i = 0
			while(not plus[i]):
				i += 1
			sum += float(working[:i + 1])
			plus >>= i + 1
			working = working[i + 1:]
		sum += float(working)
	
	print(f"{sum:.0f}")

	return 0
}

