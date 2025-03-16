#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char buf[512];
    int len;

    cin.getline(buf, sizeof(buf));
    len = strlen(buf);

    cout << buf[0] << len-3 << buf[len-2] << endl;

    return 0;
}

