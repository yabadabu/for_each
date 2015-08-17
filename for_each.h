#ifndef INC_UTILS_FOR_EACH_H_
#define INC_UTILS_FOR_EACH_H_

#define EXPAND(x)     x
#define DEF_AUX_NARGS(x1,x2,x3,x4,x5,x6,x7,x8,VAL, ... )   VAL
#define NARGS(...)          EXPAND(DEF_AUX_NARGS(__VA_ARGS__,8,7,6,5,4,3,2,1,0))

// --------------------------------------------------
#define FE0_1(what,x)       EXPAND(what(x))
#define FE0_2(what,x, ...)  EXPAND(what(x)FE0_1(what, __VA_ARGS__))
#define FE0_3(what,x, ...)  EXPAND(what(x)FE0_2(what, __VA_ARGS__))
#define FE0_4(what,x, ...)  EXPAND(what(x)FE0_3(what, __VA_ARGS__))
#define FE0_5(what,x, ...)  EXPAND(what(x)FE0_4(what, __VA_ARGS__))
#define FE0_6(what,x, ...)  EXPAND(what(x)FE0_5(what, __VA_ARGS__))
#define FE0_7(what,x, ...)  EXPAND(what(x)FE0_6(what, __VA_ARGS__))
#define FE0_8(what,x, ...)  EXPAND(what(x)FE0_7(what, __VA_ARGS__))

#define REPEAT0_(...)       EXPAND(DEF_AUX_NARGS(__VA_ARGS__,FE0_8,FE0_7,FE0_6,FE0_5,FE0_4,FE0_3,FE0_2,FE0_1,0))
#define FOR_EACH(what,...)  EXPAND(REPEAT0_(__VA_ARGS__)(what,__VA_ARGS__))

// --------------------------------------------------
#define FE1_1(what,x, y)       EXPAND(what(x,y))
#define FE1_2(what,x, y, ...)  EXPAND(what(x,y)FE1_1(what,x, __VA_ARGS__))
#define FE1_3(what,x, y, ...)  EXPAND(what(x,y)FE1_2(what,x, __VA_ARGS__))
#define FE1_4(what,x, y, ...)  EXPAND(what(x,y)FE1_3(what,x, __VA_ARGS__))
#define FE1_5(what,x, y, ...)  EXPAND(what(x,y)FE1_4(what,x, __VA_ARGS__))
#define FE1_6(what,x, y, ...)  EXPAND(what(x,y)FE1_5(what,x, __VA_ARGS__))
#define FE1_7(what,x, y, ...)  EXPAND(what(x,y)FE1_6(what,x, __VA_ARGS__))
#define FE1_8(what,x, y, ...)  EXPAND(what(x,y)FE1_7(what,x, __VA_ARGS__))

#define REPEAT1_(...)  EXPAND(DEF_AUX_NARGS(__VA_ARGS__,FE1_8,FE1_7,FE1_6,FE1_5,FE1_4,FE1_3,FE1_2,FE1_1,0))
#define FOR_EACH_PIVOT_1ST_ARG(what,arg0,...)  EXPAND(REPEAT1_(__VA_ARGS__)(what,arg0,__VA_ARGS__))

// --------------------------------------------------
#define APPLY1(FN,x,y)      EXPAND(FN(x,y))
#define APPLY2(FN,x,y,...)  EXPAND(FN(x,y)APPLY1(FN,__VA_ARGS__))
#define APPLY3(FN,x,y,...)  EXPAND(FN(x,y)APPLY2(FN,__VA_ARGS__))
#define APPLY4(FN,x,y,...)  EXPAND(FN(x,y)APPLY3(FN,__VA_ARGS__))

#define NPAIRARGS(...)        EXPAND(DEF_AUX_NARGS(__VA_ARGS__,4,4,3,3,2,2,1,1))
#define APPLYNPAIRARGS(...)   EXPAND(DEF_AUX_NARGS(__VA_ARGS__,APPLY4,APPLY4,APPLY3,APPLY3,APPLY2,APPLY2,APPLY1,APPLY1))
#define FOR_EACH_PAIR(FN,...) EXPAND(APPLYNPAIRARGS(__VA_ARGS__)(FN,__VA_ARGS__))

// --------------------------------------------------

#endif
