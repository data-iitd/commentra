#include <bits/stdc++.h>

using namespace std;

// I/O
struct Reader {
	FILE* fp;
	char buf[1 << 15], *p, *end;
	Reader() {
		fp = fopen("codejam/test_files/Y14R5P1/A.in", "r");
		p = buf;
		end = buf + fread(buf, 1, sizeof(buf), fp);
	}
	~Reader() { fclose(fp); }
	char read() {
		if (p == end) {
			p = buf;
			end = buf + fread(buf, 1, sizeof(buf), fp);
			if (end == buf) return -1;
		}
		return *p++;
	}
	void skip() { while (read()!= -1 && isspace(*p)); }
	int nextInt() {
		int x = 0;
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble() {
		double x = 0, div = 1;
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				div *= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x / div;
	}
	char* nextStr() {
		char* s = p;
		while (read()!= -1 &&!isspace(*p));
		return s;
	}
	int nextInt(int x) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s) {
		while (read()!= -1 &&!isspace(*p)) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q, int w) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r, int q) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r, double q) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q, int w, int e) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r, int q, int p) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r, double q, double p) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q, int w, int e, int r) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r, int q, int p, int o) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r, double q, double p, double o) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q, int w, int e, int r, int t) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r, int q, int p, int o, int i) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r, double q, double p, double o, double i) {
		skip();
		int c = read();
		for (; c > 32; c = read()) {
			if (c == '.') {
				double d = 1;
				while (c = read(), '0' <= c && c <= '9') {
					x += (c - 48) * d;
					d *= 0.1;
				}
				x /= pow(10, d-1);
			} else {
				x = x*10 + c - 48;
			}
		}
		return x;
	}
	char* nextStr(char* s, int n, int m, int o, int p, int q, int r, int q, int w, int e, int r, int t, int y) {
		while (read()!= -1 &&!isspace(*p) && n--) *s++ = *p;
		*s = 0;
		return p;
	}
	int nextInt(int x, int y, int z, int w, int v, int u, int t, int s, int r, int q, int p, int o, int i, int u) {
		skip();
		int c = read();
		for (; c > 32; c = read()) x = x*10 + c - 48;
		return x;
	}
	double nextDouble(double x, double y, double z, double w, double v, double u, double t, double s, double r, double q, double p, double o, double i, double u) {
		skip();
		in