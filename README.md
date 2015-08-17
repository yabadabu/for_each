# for_each
C/C++ Preprocessor macros to repeat code for each argument given

```c

  #define PRINT(x)          printf( "--%s--\n", #x);
  #define PRINT_2ARGS(x,y)  printf( "--%s : %s--\n", #x, #y);
  
  FOR_EACH(PRINT, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1--
  --2--
  --3--
  --4--
  --john--
  --sugar--
  */

  FOR_EACH_PIVOT_1ST_ARG(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1 : 2--
  --1 : 3--
  --1 : 4--
  --1 : john--
  --1 : sugar--
  */

  FOR_EACH_PAIR(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1 : 2--
  --3 : 4--
  --john : sugar--
  */
