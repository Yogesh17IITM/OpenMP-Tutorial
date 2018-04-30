// This program is to demonstrate how to divide the loop iterations among threads acc. to "schedule" Clause

// For more details about the OpenMP Directives and Clauses, one can refer the following webpage.
// Link: http://scc.ustc.edu.cn/zlsc/sugon/intel/compiler_c/main_cls/optaps/common/optaps_par_dirs.htm

// Notes on outputs: One can notice that no. of iterations performed by each thread based on the chunk size.

#include<stdio.h>
#include<omp.h>

main()
{
    int i,tid, nth;     // (i- iter; tid- thread ID; nth- no. of threads)
    int N=5,  chunk=2;  // (N- no. of iter; chunk- no. of iter. divided among threads)
    omp_set_num_threads(4);

    #pragma omp parallel private(i,tid) shared(N,nth,chunk)
    {
      tid = omp_get_thread_num();
      nth = omp_get_num_threads();

      // Syntax for dividing the iterations among threads:
      // #pragma omp for schedule(type, [chunk])
      // Type can be static (used here) or dynamic (used in the next example)

      #pragma omp for schedule (static,chunk)
      for(i=0;i<N;i++)
      {
        printf("This is iter: %d handled by thread: %d out of %d \n",i,tid,nth);
      }
    }
}


// Aliter:
// main()
// {
//     int i,tid, nth;     // (i- iter; tid- thread ID; nth- no. of threads)
//     int N=5,  chunk=2;  // (N- no. of iter; chunk- no. of iter. divided among threads)
//     omp_set_num_threads(4);
//
//     #pragma omp parallel for schedule (static, chunk)
//     for(i=0;i<N;i++)
//     {
//       tid = omp_get_thread_num();
//       nth = omp_get_num_threads();
//       printf("This is iter: %d handled by thread: %d out of %d \n",i,tid,nth);
//     }
// }