#include <stdlib.h>
//newly added
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
  //allocat memory
  char *result = (char*) calloc (strlen(str) + 1, sizeof(char));
  int i,j = 0;
  for(i=0; str[i]; i++){
    
    char checkStr[1] = {str[i]};
    if (strpbrk(checkStr,"AEIOUaeiou")){
    }
    else{
      result[j++] = str[i];
    }
  }
  result[j] = '\0';
  return (char*) result;
  //return (char*) "";
}