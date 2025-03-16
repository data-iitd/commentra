#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int n, k;
    int *as;
    as = (int *)malloc(sizeof(int) * 1000000);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }
    printf("%d\n", new Calculator(n, k, as).calculate());
    return 0;
}

class Calculator {
    private:
        int k;
        int answer;
        bool isCalculate;
        List<List<int>> lists;
    public:
        Calculator(int n, int k, List<int> as) {
            this->k = k;
            this->answer = 0;
            this->isCalculate = false;
            this->lists = new ArrayList<List<int>>();
            for (int i = 0; i < n; i++) {
                this->lists.add(new ArrayList<int>());
            }
            for (int i = 0; i < n; i++) {
                int j = as.get(i);
                if (0 < i) {
                    this->lists.get(j).add(i);
                } else if (0 < j) {
                    this->answer++;
                }
            }
        }
        int calculate() {
            if (!this->isCalculate) {
                this->dfs(0, 0);
                this->isCalculate = true;
            }
            return this->answer;
        }
        private:
        int dfs(int a, int pre) {
            int h = 0;
            for (int i : this->lists.get(a)) {
                h = Math.max(h, this->dfs(i, a));
            }
            if (0 < pre && h == this->k - 1) {
                h = 0;
                this->answer++;
            } else {
                h++;
            }
            return h;
        }
};

