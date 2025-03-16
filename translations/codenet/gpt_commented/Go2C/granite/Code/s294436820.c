
#include <stdio.h>
#include <stdlib.h>

// Define large prime constants for calculations
#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// Simple math functions
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int** m = (int**)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
    }

    for (int i = 0; i < h; i++) {
        char buf[1000];
        fgets(buf, 1000, stdin);
        for (int j = 0; j < w; j++) {
            m[i][j] = buf[j] - '0';
        }
    }

    int result = solve(h, w, k, m);
    printf("%d\n", result);

    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);
    free(buf);

    return 0;
}

int countBlack(int h, int w, int*** m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            count += m[i][j];
        }
    }
    return count;
}

int solve(int h, int w, int k, int*** m) {
    int result = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int*)malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * h);
    for (int j = 0; j < h; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int*) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}



int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    int*** m = (int***)malloc(sizeof(int) * w);
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k)
}


int main() {
    int h, w, k;
    scanf("%d %d %d
}


int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}




int main() {
    int h, w, k;
    scanf("%d %d %d
}

int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d
}


int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}


int main() {
    int h, w, k;
    scanf("%d %d %d
}

int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}




int main() {
    int h, w, k;
    scanf("%d %d
}

int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}
int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
    return result;
}
int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i] = 1;
        }
}
int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }
}


int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
        }



int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
	}
	return result;
}




}


int main() {
    int h, w, k;
    scanf("%d %d
}
int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
        m[i][j] = 1;
}
int main() {
    int h, w, k;
    for (int j = 0; j < w; j) {
    return result;
}

int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
    int h, w, k;
    for (int j = 0; j < w; j++) {
    }
int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
    }
	return result;
}
}

int main() {
    int h, w, k;
    for (int j = 0; j < w; j++) {
    int h, w, k;
    for (int j = 0; j)
}
int main() {
    int h, w, k;
}
int main() {
    int h, w, k;
}
func main() {
    int h, w, k;
}

int main() {
    int h, w, k;
}
func main() {
    int h, w, k;
}
int main() {
    int h, w, k;
}
int main() {
    int h, w, k;
}
int main() {
    int h, w, k)
	return result;
}
}

int main() {
    int h, w, k;
}
func main() {
    int h, w, k;
}
int main() {
    int h, w, k;
	return result;
}
}
int main() {
    int h, w, k;
}
	return result;
}
func main() {
    int h, w, k;
}
int main() {
    int h, w, k;
func main() {
    int h, w, k)
	return result;
}
func main() {
    int h, w, k)
}
func main() {
    int h, w, k)
	return result;
}
}
	int main() {
    int h, w, k)
	return result;
}
int main() {
    int h, w, k) {
    int h, w, k)
}
	return result;
}
int main() {
    int h, w, k)
}
	return result;
}
int main() {
    int h, w, k)
}
int main() {
    int h, w, k)
}
int main() {
    int h, w, k)
}
	return result;
}
int main() {
    int h, w, k)
	return result;
}
int main() {
    int h, w, k)
}
int main() {
    int h, w, k
}
int main() {
    int h, w, k)
	return result;
}
	return result;
}
	int main() {
    int h, w, k)
	return result;
}
	int main() {
    int h, w, k)
	return result;
}
	int main() {
    int h, w, k)
	return result;
}
	