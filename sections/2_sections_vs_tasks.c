// Taken from: https://computing.llnl.gov

#include <omp.h>
#define N 100000000

float a[N], b[N], c[N], d[N];

int main(int argc, char *argv[]) {

  int i;

  /* Some initializations */
  for (i=0; i < N; i++) {
    a[i] = i * 1.5;
    b[i] = i + 22.35;
  }

#pragma omp parallel default(none) shared(a,b,c,d) private(i)
  {
    #pragma omp single
    {
      #pragma omp task
      for (i=0; i < N; i++)
        c[i] = a[i] + b[i];

      #pragma omp task
      for (i=0; i < N; i++)
        d[i] = a[i] * b[i];
    }
  }  /* end of parallel region */

  return 0;
}
