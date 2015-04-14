#include"string.h"

/*
 * Initializes a string object.
 * Does not assume self exists.
 */

void* String_init(void* self, char* val) {
 
  String* working = self;
  
  if(working) { // make sure you're not doing something silly
 
    *(working->str) = *val;

  }

  return working;

}

/*
 * Gets a substring from head (included) to tail (excluded).
 * If tail is longer than the string in the object, substr will return up to 
 * the terminating character.
 */

void* String_substr(void* self, int head, int tail) {
  
  String* working = self;
  String newstr;
  char* substring;
  int i;

  if (head >= 0 && tail < 80 && tail > head) {
    substring=malloc(tail - head);
    
    for (i = head; i < tail; i++) {
      
      if (*(working->str + i)){
 
        *(substring + i) = *(working->str + i);

      } else {
        
        break;

      }

    }
    
    *(substring + i) = '\0';

    return String_new(sizeof(String), newstr, substring);
  }
  
  return NULL;

}

/*
 *
 */
void* String_find(void* self, char* sub) {

  String* working = self;
  char* begin = working->str;

  
 
  return NULL;
}

