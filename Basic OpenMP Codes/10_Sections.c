// This program illustrates how to split-up the work among team members (i.e., threads) using 'section'  directive

#include<stdio.h>
#include<omp.h>

main()
{
  int tid, nth;
  omp_set_num_threads(4);

  #pragma omp parallel private(tid) shared(nth)
  {
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();
    #pragma omp sections
    {
        #pragma omp section
        {
          printf("Section 1 is handled by thread %d out of %d \n",tid,nth);
        }

        #pragma omp section
        {
          printf("Section 2 is handled by thread %d out of %d \n",tid,nth);
        }
    }
  }  
  printf("\n Please note that the order is NOT DETERMINISTIC \n");
}
