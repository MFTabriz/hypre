#ifndef EUCLID_CONF_DH
#define EUCLID_CONF_DH

/*
Caution: you must have a XXX_GET_ROW defined, e.g:

  #define HYPRE_GET_ROW
  #define PETSC_GET_ROW
  #define EUCLID_GET_ROW

This is probably best accomplished in the makefile; 
If you're building an interface to a solver package,
you need to write EUCLID_GET_ROW() functions: see src/getRow.c
*/


  /* top-level error handlers. redefine to do what you want, or don't
     use it at all.  Intended usage for calling Euclid functions from
     main is:

         Euclid_dhPhoo(); ERRCHKA;
  */


#define ERRCHKA   \
    if (errFlag_dh) {  \
      setError_dh("", __FUNC__, __FILE__, __LINE__); \
      if (logFile != NULL) {  \
        printErrorMsg(logFile);  \
        closeLogfile_dh();  \
      } \
      printErrorMsg(stderr);  \
      exit(-1); \
    } 


  /* let Euclid do its thing, before handing off to PETSc;
     this is only used in main(), after a call to a function
     from the PETSc library.
   */
#define ERRCHKA_CHKERRA(ierr)   \
    if (errFlag_dh) {  \
      setError_dh("", __FUNC__, __FILE__, __LINE__); \
      if (logFile != NULL) {  \
        printErrorMsg(logFile);  \
        fprintf(logFile, "\n[%i] ierr = %i, errFlag_dh = %i\n", myid_dh, ierr, errFlag_dh); \
        closeLogfile_dh();  \
      } \
      printErrorMsg(stderr);  \
      fprintf(stderr, "\n[%i] ierr = %i, errFlag_dh = %i\n", myid_dh, ierr, errFlag_dh); \
      CHKERRA(ierr); \
    } 




#define MAX_SUBDOMAINS  20   
  /* The maximum number of subdomains into which
     the matrix may be partitioned.  Rule of thumb:
     MAX_SUBDOMAINS >= number of threads.

     Note: this is only for shared-memory.
   */


#define PIVOT_FIX_DEFAULT  1e-3

/*---------------------------------------------------------------------
 * Memory management.  These macros work with functions in Mem_dh.c;
 * Change if you want to use some memory management and reporting schemes 
 * other than that supplied with Euclid.   These depend on the global
 * object "Mem_dh mem_dh" which is defined in globalObjects.c (yuck!)
 ---------------------------------------------------------------------*/

#undef USE_PETSC_MALLOC

#ifdef USE_PETSC_MALLOC
#define MALLOC_DH(s)  PetscMalloc(s)
#define FREE_DH(p)    PetscFree(p)

#else
#define MALLOC_DH(s)  Mem_dhMalloc(mem_dh, (s))
#define FREE_DH(p)    Mem_dhFree(mem_dh, p)
#endif


  /* The actual calls used by Mem_dh objects to allocate/free memory 
   * from the heap.
   */
#define PRIVATE_MALLOC  malloc
#define PRIVATE_FREE    free

/*------------------ Memory management end -----------------------------*/

#endif
