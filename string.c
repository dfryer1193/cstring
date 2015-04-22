#include"string.h"

/*
 * Initializes a string object.
 * Does not assume self exists.
 */

String String_init(String self, char* val) {

  if(&self) { // make sure you're not doing something silly
 
    self.str = val;
    
    self.init = String_init;
    
    self.substr = String_substr;
    self.find = String_find;
    self.append = String_append;
    self.findchar = String_findchar;
    self.contains = String_contains;
    self.destroy = String_destroy;

  }

  return self;

}

/*
 * Gets a substring from head (included) to tail (excluded).
 * If tail is longer than the string in the object, substr will return up to 
 * the terminating character.
 */

String* String_substr(String self, int head, int tail) {
  
  String newstr;
  char* substring;
  int i;

  if (head >= 0 && tail < 80 && tail > head) {
    substring=malloc(tail - head);
    
    for (i = head; i < tail; i++) {
      
      if (*(self.str + i)){
 
        *(substring + i) = *(self.str);

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

String* String_find(String self, String sub) {

  char* begin = self.str;
  int index;

  index = self.findchar(self, *begin, 0);

  while (*(self.str + index) && (*(self.str + index))) {
  }
 
  return NULL;
}

void String_append(String self, String str) {
  return;
}

int String_findchar(String self, char character, int index) {
  return -1;
}

void String_destroy(String self) {
  return;
}
