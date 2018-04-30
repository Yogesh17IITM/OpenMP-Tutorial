// Private Vs. Shared example

#include<stdio.h>
#include<omp.h>

main()
{
  int tid, nt;
  omp_set_num_threads(4);
  printf("\n Demonstrating Private Vs Shared clause \n \n");
  #pragma omp parallel private(tid) shared(nt)
  {
    tid = omp_get_thread_num();
    nt = omp_get_num_threads();
    printf("This is thread = %d out of %d \n", tid, nt);
  }

  // Following message will be displayed in the terminal
  printf("\n Note: \n");
  printf("'tid' --> is private to each thread (private(tid))\n");
  printf("'nt'  --> is shared among threads (shared(nt)) \n");
}
