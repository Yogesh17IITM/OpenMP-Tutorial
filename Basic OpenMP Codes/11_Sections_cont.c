#include<stdio.h>
#include<omp.h>

main()
{
  int tid, nth;
  omp_set_num_threads(2);

  #pragma omp parallel private(tid) shared(nth)
  {
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();

    #pragma omp sections
    {
      #pragma omp section
      printf("Section 1 is handled by %d out of %d \n",tid,nth);

      // below are simple copy-pasted
      #pragma omp section
      printf("Section 2 is handled by %d out of %d \n",tid,nth);

      #pragma omp section
      printf("Section 3 is handled by %d out of %d \n",tid,nth);

      #pragma omp section
      printf("Section 4 is handled by %d out of %d \n",tid,nth);
    }
  }
  printf("Choice of thread: NOT DETERMINISTIC");
}
