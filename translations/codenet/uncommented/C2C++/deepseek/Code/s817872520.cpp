#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 0x5fffffff;
int a[100002];
int b[100002];

string buf;
size_t p;

int getint()
{
	int n = 0;
	if (buf[p] == '-') {
		p++; while (buf[p] >= '0') n = (n*3) + (n*3) + (buf[p++] & 0xf);
		return -n;
	}
	while (buf[p] >= '0') n = (n*3) + (n*3) + (buf[p++] & 0xf);
	return n;
}

int main()
{
	int w, i, k, f, close, ans;

	getline(cin, buf);
	w = getint();
	getline(cin, buf);
	p = 0;
	for (ans = 0, f = 0, i = 1; i <= w; i++) {
		a[i] = k = getint();
		p++;
		if (!k) f |= 1;
		else if (k < 0) f |= 2;
		else ans += k;
	}
	if (!ans || !(f & 1)) { cout << "0" << endl; return 0; }
	if (!(f & 2)) { cout << ans << endl; return 0; }

	for (close = 0, f = 0, i = 1; i <= w; i++) {
		if (!a[i]) close = INF, f = -1;
		else if (a[i] < 0) {
			if (f < 0 || close - (i-f) > -a[i]) close = -a[i], f = i;
		} else {
			if (f < 0) b[i] = INF;
			else {
				k = close - (i-f); if (k < 0) k = 0;
				b[i] = k;
			}
		}
	}

	for (close = 0, f = w, i = w; i >= 1; i--) {
		if (!a[i]) close = INF, f = -1;
		else if (a[i] < 0) {
			if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
		} else {
			if (f < 0) b[i] = INF;
			else {
				k = close - (f-i); if (k < 0) k = 0;
				if (k > b[i]) b[i] = k;
			}
		}
	}

	for (ans = 0, i = 1; i <= w; i++) {
		if (a[i] > 0) {
			if (b[i] > a[i]) ans += a[i];
			else             ans += b[i];
		}
	}
	cout << ans << endl;
	return 0;
}
