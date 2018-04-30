// This program is to demonstrate how the serial and parallel code works

////////////////// SERIAL CODE ///////////////////////////
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// {
// int id = 0;
// int np = 1;
// printf( "Hello world %d of %d\n", id, np );
// }
// return 0;
// }

////////////////// PARALLEL CODE ////////////////////////
// Note 1: The type of directive used is "parallel" in which the task exists within the parallel loop will be executed by each thread
// Note 2: Variables declared outside of the parallel region are shared by all threads
// Note 3: If "int id" is declared outside the parallel region, it will give erroneous output. As an eg, consider 6 threads and see the results.
// Note 4: The above issue can be controlled by using "private(<tid>)" clause.
// This will be demonstrated in the upcoming example ("Shared Vs. Private clause").

#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    int np = omp_get_num_threads();
    printf( "Hello world %d of %d\n", id, np );
  }
  return 0;
}
