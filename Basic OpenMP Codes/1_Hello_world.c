// This program demonstrates how to run and compile a simple "Hello World" program using OpenMP

// To compile : gcc -fopenmp <filename>.c
// To run     : ./a.out
// Platform   : Linux (Ubuntu)
// To check CPU details: type "lscpu" in the terminal
// For better visualisation, use "Atom editor".

#include <omp.h>
#include <stdio.h>
main ()
{
      int tid ;
      // "tid" is declared outside parallel region which may give erroneous output
      // So "private(tid)" is used to control that output.
      // This will be demonstrated in the next example.

      omp_set_num_threads(3);       // --> Run time library routine
      #pragma omp parallel private(tid)   // --> compiler directive (with "private" clause)
      {
          tid = omp_get_thread_num(); // --> Run time library routine
          printf("Hello World from thread = %d \n", tid);
      }
      printf("\n # Order not deterministic # \n");
      printf("\n Out of parallel region \n");

      // Please skip reading this and proceed further. Cheers !!!
      printf("\n Before coding you'll feel: OMG !! What is this??");
      printf("\n  After coding you'll feel: What is the big deal with this !! \n");
      printf("\n Feel the difference. Enjoy coding :) \n");
}

//  References:
//  Yun (Helen), NERSC
//  William Gropp, Illinois
//  Van Criekingen, UPJV / MeCS

// Noticed any bugs?
// please write to me: am16d028@smail.iitm.ac.in
// by 
// Yogesh, FSI Lab, IIT Madras
