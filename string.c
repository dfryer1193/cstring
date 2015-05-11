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

  if (head >= 0 && tail < STR_LEN && tail > head) {
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
 * Returns the index of the end of the string. -1 means sub was not found
 */

int String_contains(String self, String sub, int index) {

  char* begin = sub.str;
  char* start = self.str + index;
  int sub_index=0;

  index = self.findchar(self, *begin, index);
  if (index == -1) {
    return -1;
  }

  for (sub_index; *(begin + sub_index) != '\0' && sub_index < STR_LEN; sub_index++) {

    if (*(begin + sub_index) != *(start + index)) {

      sub_index = 0;
      index = self.findchar(self, *begin, index);

      if (index < 0) {
      
        return -1;
      }

    } else {
      
      index++;
      
      if  (*(start + index) == '\0' && *(begin + sub_index + 1) != '\0') {
        
        return -1;
      }

    }

  }

  return index + 1;
}

void String_append(String self, String str) {
  char* p_self;
  char* p_add;

  p_self = (self.str + self.findchar(self, '\0', 0));
  p_add = str.str;

  while ((*p_self++ = *p_add++) != '\0');

  return;
}

int String_findchar(String self, char character, int index) {
  
  char* curchar = self.str;
  curchar += index;
  
  while (curchar - self.str < STR_LEN) {
  
    if (*curchar == character) {
      
      return curchar - self.str;
    
    }

    curchar++;
  }

  return -1;
}

void String_destroy(String self) {
  return;
}
