// single/ master principle
// Both are used to execute the given task by using ONLY ONE THREAD
// But there is shutle difference between them. Look at the example below.

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

    #pragma omp single // master
    {
      printf("Thread no: %d out of %d \n",tid,nth);
    }
  }

  printf("\n Only one thread will execute the task.\n");
  printf("if master : it is DETERMINISTIC \n");
  printf("if single : it is NOT DETERMINISTIC \n");
}
