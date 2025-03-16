
#include <bits/stdc++.h>

using namespace std;

// I/O
struct Reader {
	FILE* in;
	int b;
	char buf[10240];
	int cur;
	int end;
	int len;
	Reader() {
		in = fopen("codejam/test_files/Y14R5P1/A.in.txt", "r");
		b = fgetc(in);
		cur = 0;
		end = 0;
		len = 0;
	}
	void nextChar() {
		if (cur == end) {
			cur = 0;
			end = fread(buf, 1, 10240, in);
			if (end <= 0) {
				b = -1;
			} else {
				b = buf[0];
			}
		} else {
			b = buf[cur++];
		}
		len++;
	}
	void nextStr(char* s) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				if (i > 0) {
					s[i] = 0;
					return;
				} else {
					if (b == -1) {
						s[0] = 0;
						return;
					} else {
						continue;
					}
				}
			}
			s[i++] = b;
		}
	}
	int nextInt() {
		int a = 0;
		bool neg = false;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				break;
			}
			if (b == '-') {
				neg = true;
				continue;
			}
			a = a*10 + b - '0';
		}
		if (neg) {
			return -a;
		}
		return a;
	}
	double nextDouble() {
		double a = 0, d = 1;
		bool neg = false;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				break;
			}
			if (b == '-') {
				neg = true;
				continue;
			}
			if (b == '.') {
				continue;
			}
			a = a*10 + b - '0';
			d *= 10;
		}
		if (neg) {
			return -a / d;
		}
		return a / d;
	}
	char* nextToken() {
		static char s[10240];
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				if (i > 0) {
					s[i] = 0;
					return s;
				} else {
					if (b == -1) {
						s[0] = 0;
						return s;
					} else {
						continue;
					}
				}
			}
			s[i++] = b;
		}
	}
	int nextIntToken() {
		int a = 0;
		bool neg = false;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				break;
			}
			if (b == '-') {
				neg = true;
				continue;
			}
			a = a*10 + b - '0';
		}
		if (neg) {
			return -a;
		}
		return a;
	}
	double nextDoubleToken() {
		double a = 0, d = 1;
		bool neg = false;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b =='' || b == '\n' || b == '\r' || b == '\t') {
				break;
			}
			if (b == '-') {
				neg = true;
				continue;
			}
			if (b == '.') {
				continue;
			}
			a = a*10 + b - '0';
			d *= 10;
		}
		if (neg) {
			return -a / d;
		}
		return a / d;
	}
	int nextIntLine(int* a) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
		}
	}
	int nextIntLine(int* a, int n) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
		}
	}
	int nextIntLine(int* a, int l, int r) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == r) {
				return i;
			}
			if (i == l) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int l, int r, int n) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == r) {
				return i;
			}
			if (i == l) {
				i = 0;
			}
			if (i == n) {
				return i;
			}
		}
	}
	int nextIntLine(int* a, int n, int m) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o, int p) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
			if (i == p) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o, int p, int q) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
			if (i == p) {
				i = 0;
			}
			if (i == q) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o, int p, int q, int r) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
			if (i == p) {
				i = 0;
			}
			if (i == q) {
				i = 0;
			}
			if (i == r) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o, int p, int q, int r, int s) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
			if (i == p) {
				i = 0;
			}
			if (i == q) {
				i = 0;
			}
			if (i == r) {
				i = 0;
			}
			if (i == s) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int m, int o, int p, int q, int r, int s, int t) {
		int i = 0;
		while (1) {
			if (cur == end) {
				cur = 0;
				end = fread(buf, 1, 10240, in);
				if (end <= 0) {
					b = -1;
				} else {
					b = buf[0];
				}
			} else {
				b = buf[cur++];
			}
			if (b == -1 || b == '\n' || b == '\r') {
				if (i > 0) {
					a[i] = 0;
					return i;
				} else {
					if (b == -1) {
						return i;
					} else {
						continue;
					}
				}
			}
			a[i++] = b - '0';
			if (i == n) {
				return i;
			}
			if (i == m) {
				i = 0;
			}
			if (i == o) {
				i = 0;
			}
			if (i == p) {
				i = 0;
			}
			if (i == q) {
				i = 0;
			}
			if (i == r) {
				i = 0;
			}
			if (i == s) {
				i = 0;
			}
			if (i == t) {
				i = 0;
			}
		}
	}
	int nextIntLine(int* a, int n, int