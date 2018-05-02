// Code enclosed in critical region will be executed by one thread at a time
// Using << atomic >> instead of << critical >>, will give same outputs.

#include<stdio.h>
#include<omp.h>

main ()
{
  int x=0;
  omp_set_num_threads(4);
 #pragma omp parallel shared(x)
  {
    #pragma omp critical      // Also, see the results without << critical >>
    {      x = x+1;     }
  }
  printf("At the end x= %d \n",x);
}

// Q1) If you replace, << critical >> by  << single >>, what will happen?
// Ans >>
// In "single", the task within the region will be executed only once
// where as in "critical", the no. of times task executed will be equal to the omp_num_threads() specified above.

// Q2) Can I get the same outout using for loop? Say, for instance, consider the following code and compare the results with the above code.
// main ()
// {
//   int i, x=0, tid;
//   omp_set_num_threads(4);
//
//   #pragma omp parallel for
//   for(i=0;i<4;i++)
//   {
//       tid = omp_get_thread_num();
//       x=x+1;
//       printf("x = %d calc. by thread %d \n",x, tid);
//   }
//   printf("At the end x= %d \n",x);
// }
