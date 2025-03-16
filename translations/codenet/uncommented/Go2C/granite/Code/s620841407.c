
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **edges = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        edges[i] = (int *)malloc(sizeof(int) * (n - 1));
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        edges[x][i] = y;
        edges[y][i] = x;
    }

    ll (*f)(int, int) = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)));
    *f = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    for (int i = 0; i < n; i++) {
        (*f)[i] = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    }

    ll (*g)(int, int) = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    for (int i = 0; i < n; i++) {
        (*g)[i] = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    }

    ll (*dp)(int, int) = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (ll (*)(int, int))malloc(sizeof(ll (*)(int, int)) * n);
    }

    ll (*res)(int) = (ll (*)(int))malloc(sizeof(ll (*)(int)) * n);

    ll identity = 0;
    ll (*oper)(ll, ll) = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *oper = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)) * m);
    for (int i = 0; i < m; i++) {
        (*oper)[i] = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)) * m);
    }

    ll (*operNode)(ll, int) = (ll (*)(ll, int))malloc(sizeof(ll (*)(ll, int)) * m);
    for (int i = 0; i < m; i++) {
        (*operNode)[i] = (ll (*)(ll, int))malloc(sizeof(ll (*)(ll, int)) * m);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            (*oper)[i][j] = 0;
            (*operNode)[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        (*oper)[i][i] = 1;
        (*operNode)[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int x = edges[i][j];
            (*f)[i][x] = 0;
            (*g)[i][x] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*f)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*g)[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*dp)[i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
		dp)[i][j] = 0;
	}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		dp := make([]int, m)
		}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		dp := make([]int, m)
		}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		dp := make([]int, m)
	}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for i = 0; i < n; i++) {
			(*f)[i][j] = 0;
	}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		dp := make([]int, m)
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for k = 0; k < n; k++) {
		for l = 0; l < n; l++) {
		for m = 0; m < n; m++) {
		for n = 0; n < n; n++) {
		res[i] = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for k = 0; k < n; k++) {
		for l = 0; l < n; l++) {
		dp := make([]int, m)
	}

	for i = 0; i < n; i++) {
		res[i] = 0;
	}

	for j = 0; j < n; j++) {
		for k = 0; k < n; k++) {
		for l = 0; l < n; l++) {
		for m = 0; m < n; m++) {
		res[i] = 0;
	}

	for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for i = 0; i < n; i++) {
		dp := make([]int, m)
	}

	for i = 0; i < n; i++) {
		res[i] = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for k = 0; k < n; k++) {
		for l = 0; l < n; l++) {
		for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		for i = 0; i < n; i++) {
		for j = 0; j < n; j++) {
		res[i] = 0; i < n; i < n; i++) {
		for