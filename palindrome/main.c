#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  //newly added
  char *palindromeOpt;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  while (fgets(line, size, stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    //newly added
    // use the palindromeopt to store the output of the palindrome(line) 
    palindromeOpt = palindrome(line);
    printf("Is the string <%s> a palindrome? %s\n", line, palindromeOpt);
    free(palindromeOpt);
  }

  free(line);
}
