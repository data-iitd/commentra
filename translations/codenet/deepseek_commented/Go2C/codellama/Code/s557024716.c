
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INF_INT 2147483647
#define INF_BIT 1 << 30
#define NIL -1

#define MAX_N 100000
#define MAX_K 100000

int a, b, c, k;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &k);

    int patterns[MAX_K][MAX_K];
    int pattern_num = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            patterns[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        patterns[i][i] = 1;
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 0;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 1;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 3;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 2;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 1;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 3) {
                patterns[i][j] = 3;
            }
        }
    }

    pattern_num++;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                patterns[i][j] = 2;
            } else if (patterns[i][j] == 2) {
                patterns[i][j] = 3;
            } else if (patterns[