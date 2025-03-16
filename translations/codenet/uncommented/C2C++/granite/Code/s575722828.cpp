
#include <iostream>
using namespace std;

int main()
{
int S;

cin >> S;


cout << (int)(S/3600) << ":" << (int)((S % 3600) / 60) << ":" << S % 60 << endl;

return 0;

}

