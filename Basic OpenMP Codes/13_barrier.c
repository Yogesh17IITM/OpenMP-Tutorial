// Next topic is SYNCHRONIZATION. It has following three elements
//  1) barrier
//  2) Critical & Atomic
//  3) Reduction
// We will see, one by one. Firstly, let us start with barrier.

// In 'barrier', thread waits until all other threads finish the task.

#include<stdio.h>
#include<omp.h>

main()
{
  int tid, nth;
  omp_set_num_threads(4);

  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    nth = omp_get_num_threads();
    printf("Task 1 from thread: %d out of %d \n",tid, nth);

    #pragma omp barrier
    {
      #pragma omp single
      {printf("\n Task 1 is completed. Now proceeding to Task 2 \n \n");}
    }

    #pragma omp barrier
    {
      printf("Task 2 from thread: %d out of %d \n", tid, nth);
    }
  }
  printf("Out of parallel region \n");
}
