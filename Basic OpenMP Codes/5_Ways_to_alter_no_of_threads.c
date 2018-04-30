// There are 3 different ways (or possibilities) to change the number of threads

#include <stdio.h>
#include <omp.h>

main ()
{
  int tid ;
  omp_set_num_threads(6);     // FIRST
  #pragma omp parallel private(tid) num_threads(4)  // SECOND
  {
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d \n", tid);
  }
}

// THIRD (can be done in the terminal)
//   1) export OMP_NUM_THREADS = 3 (say, for instance)
//   2) comment all run time library routine
//   3) compile and run to see the results.
//   4) You may notice that, it will use 3 threads (as specified abova)


// In this way, the number of threads can be controlled based on the three choices mentioned above
