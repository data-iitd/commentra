
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100000 + 10;
const int MAX_INT = 0x5fffffff;

int a[MAXN];
int b[MAXN];
char buf[700000 + 10];
char *p;

int getint()
{
	int n = 0;
	if (*p == '-') {
		p++;
		while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
		return -n;
	}
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int w, i, k, f, close, ans;

	fgets(p=buf, 10, stdin);
	w = getint();

	fgets(p=buf, sizeof(buf), stdin);
	for (ans = 0, f = 0, i = 1; i <= w; i++) {
		k = getint();
		p++;
		if (!k) {
			f |= 1;
			continue;
		}
		if (k < 0) {
			if (f < 0 || close - (i-f) > -k) close = -k, f = i;
			if (f < 0) f = -2;
		}
		ans += k;
	}

	if (!ans ||!(f & 1)) {
		cout << 0 << endl;
		return 0;
	}
	if (!(f & 2)) {
		cout << ans << endl;
		return 0;
	}

	for (close = 0, f = w, i = w; i >= 1; i--) {
		if (!a[i]) {
			close = MAX_INT;
			f = -1;
			continue;
		}
		if (a[i] < 0) {
			if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
		} else {
			b[i] = MAX_INT;
			if (f >= 0) {
				int k = close - (f-i);
				if (k < 0) k = 0;
				b[i] = k;
			}
		}
	}

	for (close = 0, f = w, i = 1; i <= w; i++) {
		if (a[i] > 0) {
			if (b[i] > a[i]) ans += a[i];
			else             ans += b[i];
		}
	}

	cout << ans << endl;
	return 0;
}

