// This program demonstrates "Dynamic thread setting"

// This requires setting OMP_DYNAMIC environment variable to TRUE.
// Eg: export OMP_DYNAMIC=TRUE
// Note: implementation dependent.

#include<stdio.h>
#include<omp.h>

main ()
{
int nthreads;
omp_set_num_threads(4);
  #pragma omp parallel shared(nthreads) // Setting Default values
  {
    nthreads = omp_get_num_threads();
    printf("Part A: number of threads = %d\n",nthreads);
  }
  printf("\n");
  /////////////////////////////////////////////////////

  #pragma omp parallel shared(nthreads) num_threads(3)
  {
    nthreads = omp_get_num_threads();
    printf("Part B: number of threads = %d\n", nthreads);
  }
  printf("\n");
  /////////////////////////////////////////////////////

  #pragma omp parallel shared(nthreads) num_threads(2)
  {
    nthreads = omp_get_num_threads();
    printf("Part C: number of threads = %d\n", nthreads);
  }
}
