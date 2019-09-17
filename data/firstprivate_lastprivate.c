#include <stdio.h>
#include <omp.h>

int
main() {

  double x = 10.0;
  double y = 1.0;

  printf("Value of x: %f\n", x);
  printf("Value of y: %f\n", y);

  printf("\nFirst parallel region\n");
#pragma omp parallel default(none) private(x, y)
  {
    printf("Value of x: %f\n", x);
    printf("Value of y: %f\n", y);
  }

  printf("\nSecond parallel region\n");
#pragma omp parallel firstprivate(x)
  {

    printf("Inside parallel region x: %f, thread: %d\n", x, omp_get_thread_num());
    printf("Inside parallel region y: %f, thread: %d\n", y, omp_get_thread_num());

#pragma omp for lastprivate(y)
    for (int i = 0; i < omp_get_num_threads(); ++i) {
      x = i + omp_get_thread_num();
      y = i + omp_get_thread_num();
    }
  }

  printf("Outside parallel region x: %f\n", x);
  printf("Outside parallel region y: %f\n", y);
  return 0;
}
