// This program demonstrates the usage of "Dynamic" type of "schedule" Clause
// This is similar to static type, except that the order of threads for which the chunk is assigned is NOT DETERMINISTIC.

#include <stdio.h>
#include<omp.h>

main ()
{
  int tid, i, nth;
  int N=5, chunk=2;

  omp_set_num_threads(10);

  #pragma omp parallel private(tid,i) shared(chunk,N, nth)
  {
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();
    #pragma omp for schedule(dynamic, chunk)
    for (i=0; i < N; i++)
    printf("This is iter: %d handled by thread: %d out of %d \n",i,tid,nth);
  }
  printf("\n Note: Here iterations assigned chunk by chunks to threads, but IN ANY ORDER \n");
}
