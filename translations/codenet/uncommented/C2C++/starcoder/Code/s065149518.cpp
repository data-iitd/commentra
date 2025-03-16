#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 21;

void init(int);
void move(int);

int n, x, y;
char fld[MAX][MAX];

int main(void) {
    int m;
    while(cin >> n, n) {
        init(n);
        cin >> m;
        move(m);
        cout << (n? "No" : "Yes") << endl;
    }
    return 0;
}

void init(int i) {
    int a, b;
    x = y = 10;
    memset(fld, 0, sizeof(fld));
    while(i--) {
        cin >> a >> b;
        fld[b][a] = 1;
    }
}

void move(int i) {
    int a, d;
    char buf[2];
    while(i--) {
        cin >> buf >> a;
        switch(buf[0]) {
          case 'N':
            d = 0;
            break;
          case 'E':
            d = 1;
            break;
          case 'S':
            d = 2;
            break;
          case 'W':
            d = 3;
            break;
        }
        while(a--) {
            d % 2? ~-d? x-- : x++ : d? y-- : y++;
            if(fld[y][x]) {
                fld[y][x] = 0;
                n--;
            }
        }
    }
}

