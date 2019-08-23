#include <stdio.h>
#include <omp.h>

static long num_steps = 10000000;
double step;

int
main() {
  
  double pi, sum, x;
  step = 1.0 / (double) num_steps;

  double start_time = omp_get_wtime();
#pragma omp parallel for reduction(+:sum) schedule(static,100) default(none) shared(step, num_steps) private(x)
  for (int i = 0; i < num_steps; ++i) {
     x = (i + 0.5) * step;
     sum += 4.0 / (1.0 + x * x);
   }
  pi = step * sum;
  double end_time = omp_get_wtime();
  printf("PI: %.10f\n", pi);
  printf("It took: %f\n", end_time - start_time);
}
