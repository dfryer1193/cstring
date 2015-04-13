#ifndef __MY_STRING
#define __MY_STRING
typedef struct String {
  char str[STR_LEN];
  char* p_str = str;
} String;
#endif
