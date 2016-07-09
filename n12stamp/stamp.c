#include <stdio.h>
#include <limits.h>

int denom[INT_MAX];
int dp[INT_MAX];

int main(int argc, const char *argv[])
{
  int k;
  int n;
  int i, j;
  int from;

  while (scanf("%d", &k) != EOF) {

    // read
    for (i = 0; i < k; i++) {
      scanf("%d", &denom[i]);
    }

    scanf("%d", &n);

    // init
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
      dp[i] = INT_MAX - 1; // prevent + 1 overflow
    }

    // solve
    for (i = 1; i <= n; i++) {
      for (j = 0; j < k; j++) {
        from = i - denom[j];
        if (from < 0) continue;

        if (dp[from] + 1 < dp[i]) {
          dp[i] = dp[from] + 1;
        }
      }
    }

    // output
    printf("%d\n", dp[n]);
  }

  return 0;
}
