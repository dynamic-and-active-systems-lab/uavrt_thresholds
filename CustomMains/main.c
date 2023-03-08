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
#include "threshold_appender.h"
#include "threshold_appender_terminate.h"

/* Function Declarations */
static void argInit_1xd200_char_T(char result_data[], int result_size[2]);

static char argInit_char_T(void);

static double argInit_real_T(void);

/* Function Definitions */
static void argInit_1xd200_char_T(char result_data[], int result_size[2])
{
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_char_T();
  }
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
    
  double sampleRate = strtof(argv[1],NULL);
  char *path = argv[2];
    
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_threshold_appender(sampleRate, path);
  /* Terminate the application.
You do not need to do this more than one time. */
  threshold_appender_terminate();
  return 0;
}

void main_threshold_appender(double sampleRate, char path_data[])
{
  int path_size[2];
  /* char path_data[200];*/
  /* Initialize function 'threshold_appender' input arguments. */
  /* Initialize function input argument 'path'. */
  /* argInit_1xd200_char_T(path_data, path_size); */
  
    int strLength;
  for (strLength = 0; path_data[strLength] != '\0'; ++strLength)
  path_size[0] = 1;
  path_size[1] = strLength;
    
       
    
  /* Call the entry-point 'threshold_appender'. */
  threshold_appender(sampleRate, path_data, path_size);
}

/* End of code generation (main.c) */
