#ifndef MY_STRING
#define MY_STRING

#include<stdlib.h>

#define STR_LEN 80 //Includes null terminator

typedef struct String String;

struct String {
  char* str;

  // Constructor
  String* (*init)     (char* val);

  // Methods
  String* (*substr)   (String* self, int head, int tail);
  String* (*find)     (String* self, String* sub);
  String* (*append)   (String* self, String* postfix);
  int     (*findchar) (String* self, char character, int index);
  int     (*contains) (String* self, String* str);
  char*   (*toString) (String* self);
  void    (*destroy)  (String* self);
};

String* String_new      (size_t size, String proto, char* val);
String* String_init     (char* val);
void    String_destroy  (String* self);

String* String_find     (String* self, String* sub);
String* String_substr   (String* self, int head, int tail);
void    String_append   (String* self, String* str);
int     String_findchar (String* self, char character, int index);
int     String_contains (String* self, String* sub);

#endif
