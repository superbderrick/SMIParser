//
//  SMIParser.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 31..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include "SMIParser.h"


char** readFile(const char * filepath) {
  FILE *file = fopen(filepath, "r");
  if(!file) {
    printf("Can't open a file , file open error from : %s" , filepath);
    return NULL;
  }
  
  //Allocate space for arrlen char *
  int arrlen = 0;
  char ** lines = NULL;
  char buf[1000];
  int i = 0;
  
  while (fgets(buf, 1000, file)) {
    
    if(i == arrlen) {
      arrlen += STEPSIZE;
      
      char ** newlines = realloc(lines, arrlen * sizeof(char *));
      if(!newlines) {
        printf("can't realloc \n");
        exit(1);
      }
      lines = newlines;
    }
    
    printf("whole line : %lu \n" , strlen(buf));
    
      buf[strlen(buf) -2] = '\0';
    printf("whole line : %lu \n" , strlen(buf));
    printf("whole line : %s \n" , buf);
    
    int slen = strlen(buf);
    
    char *str = (char *)malloc((slen+1) * sizeof(char));
    strcpy(str, buf);
    lines[i] = str;
    i++;
  }
  lines[i] = NULL;
  
  return lines;
  
}
