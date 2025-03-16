
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef long long ll;

ll gcd(ll a, ll b) { return b? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

typedef struct {
    ll key;
    ll value;
} Map;

Map* newMap() {
    Map* map = (Map*)malloc(sizeof(Map));
    map->key = 0;
    map->value = 0;
    return map;
}

Map* putMap(Map* map, ll key, ll value) {
    map->key = key;
    map->value = value;
    return map;
}

ll getMap(Map* map, ll key) {
    return map->value;
}

Map* removeMap(Map* map, ll key) {
    free(map);
    return NULL;
}

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);

    ll* A = (ll*)malloc(sizeof(ll) * (N + 1));
    for (ll i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    ll cur = 1;
    Map* dic = newMap();
    bool flg = false;

    for (ll i = 1; i <= K; i++) {
        if (getMap(dic, cur) < 0 || flg) {
            putMap(dic, cur, i);
            cur = A[cur];
        } else if (!flg) {
            ll tmp = K - (getMap(dic, cur) - 1);
            tmp %= i - getMap(dic, cur);
            i = K - tmp;
            flg = true;
        }
    }

    printf("%lld\n", cur);

    free(A);
    removeMap(dic, cur);

    return 0;
}


