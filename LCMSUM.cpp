#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define mp make_pair
#define MAX 1000000

using namespace std;

typedef pair<int, int> prime_pot;
typedef unsigned long long int64;

int64 resp[MAX], sum[MAX];

void cal_sum()
{
    for (int i = 1; i <= MAX; i++)
        sum[i] = i;
    for (int i = 2; i <= MAX; i++)
        if (sum[i] == i)
            for (int j = 2 * i; j <= MAX; j += i)
                sum[j] -= sum[j] / i;
    for (int i = 2; i <= MAX; i++)
        if (sum[i] == i)
            sum[i] = i - 1;
    for (int i = 1; i <= MAX; i++)
        for (int j = i; j <= MAX; j += i)
            resp[j] += i * sum[i];
}

int main()
{
    cal_sum();
    int64 a, n, d;
    scanf("%llu", &n);
    while (n--) {
        scanf("%llu", &a);
        printf("%llu\n", (1 + resp[a]) * a / 2);
    }
    return 0;
}
