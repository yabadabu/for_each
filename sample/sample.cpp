#include "stdafx.h"
#include <cstdio>
#include "for_each.h"

#define PRINT(x)          printf( "--%s--\n", #x);
#define PRINT_2ARGS(x,y)  printf( "--%s : %s--\n", #x, #y);

int main(int argc, char** argv)
{

  printf("FOR_EACH(PRINT, 1, 2, 3, 4, john, sugar);\n");
  FOR_EACH(PRINT, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1--
  --2--
  --3--
  --4--
  --john--
  --sugar--
  */

  printf("\nFOR_EACH_PIVOT_1ST_ARG(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);\n");
  FOR_EACH_PIVOT_1ST_ARG(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1 : 2--
  --1 : 3--
  --1 : 4--
  --1 : john--
  --1 : sugar--
  */

  printf("\nFOR_EACH_PAIR(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);\n");
  FOR_EACH_PAIR(PRINT_2ARGS, 1, 2, 3, 4, john, sugar);
  /* Output:
  --1 : 2--
  --3 : 4--
  --john : sugar--
  */

  return 0;
}



