/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "rt_nonfinite.h"
#include "tagFileThresholdAppender.h"
#include "tagFileThresholdAppender_terminate.h"


/* Function Declarations */
static emxArray_char_T *argInit_1xUnbounded_char_T(void);

static char argInit_char_T(void);

static double argInit_real_T(void);


int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
    double sampleRate = strtof(argv[1],NULL);
    char *path = argv[2];
    
    
  main_tagFileThresholdAppender(sampleRate, path);
  /* Terminate the application.
You do not need to do this more than one time. */
  tagFileThresholdAppender_terminate();
  return 0;
}

void main_tagFileThresholdAppender(double sampleRate, char path[])
{
  /* Call the entry-point 'tagFileThresholdAppender'. */
  tagFileThresholdAppender(sampleRate, path);
  
}

/* End of code generation (main.c) */
