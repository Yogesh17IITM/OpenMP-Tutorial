// This program demonstrates the use of master directive
// Note: It is often useful to have only one thread to execute some of the code in the parallel region
// Following is an example of the case mentioned above

#include<stdio.h>
#include<omp.h>

main()
{
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    int nt;

    // The Following pragma region executes once in the parallel region
    #pragma omp master
    {
      int nt_req = omp_get_num_threads();
      //int nt = omp_get_thread_num();    // Check this //
      printf("No. of threads requested: %i \n", nt_req);
      // Note: '%i' is unsigned integer
      //nt = nt_req;    // Check this //
    }

    nt = omp_get_num_threads();
    int id = omp_get_thread_num();
    printf("Hey dude. I'm thread %d of %d \n", id, nt);
  }

  printf("Hey. I am out of the parallel loop now !! \n");
  printf("Happy coding :) \n");
}
