#ifndef __MY_STRING
#define __MY_STRING

#include<stdlib.h>

#define STR_LEN 80 //Includes null terminator

typedef struct String {
  char* str;

  // Constructor
  void* (*init)     (void* self, char* val);

  // Methods
  void* (*substr)   (void* self, int head, int tail);
  void* (*findchar) (void* self, char character, int index);
  void* (*find)     (void* self, void* sub);
  void* (*append)   (void* self, void* postfix);
  int   (*contains) (void* self, void* str);
  void* (*toString) (void* self);
  void  (*destroy)  (void* self);
} String;

void* String_new      (size_t size, String proto, char* val);
void* String_init     (void* self, char* val);
void  String_destroy  (void* self);

void* String_find     (void* self, char* sub);
void* String_substr   (void* self, int head, int tail);
void  String_append   (void* self, char* str);
int   String_findchar (void* self, char character, int index);
int   String_contains (void*iself, char* sub);

#endif
