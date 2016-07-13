#include <stdio.h>
#include <limits.h>

int denom[INT_MAX];
int dp[INT_MAX];
int usage[INT_MAX];
int k;
int counterOfSolution;

void backtracking(int curr, int left, int denomIndex)
{
  int i, j;

  if (curr < 0 || left < 0 || denomIndex >= k) {
    // out of range
    return;
  }

  if (curr == 0) {
    // found answer

    counterOfSolution++;
    printf("(%d)\n", counterOfSolution);
    for (i = 0; i < k; i++) {
      if (usage[i] > 0) {
        printf("%d x %d\n", denom[i], usage[i]);
      }
    }

    return;
  }

  // use
  usage[denomIndex]++;
  backtracking(curr - denom[denomIndex], left - 1, denomIndex);
  usage[denomIndex]--;

  // not use
  backtracking(curr, left, denomIndex + 1);
}

int main(int argc, const char *argv[])
{
  int n;
  int i, j;
  int from;
  int total;

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

    total = dp[n];

    // init for backtracking
    for (i = 0; i < k; i++) {
      usage[i] = 0;
    }
    counterOfSolution = 0;

    backtracking(n, total, 0);

    // output
    printf("total:%d\n\n", total);
  }

  return 0;
}
