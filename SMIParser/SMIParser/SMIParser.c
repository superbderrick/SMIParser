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
    fprintf(stderr, "Can't open files %s" , filepath);
    return NULL;
  }
    int arrlen = 0;
  //Allocate space for arrlen char *
  char ** lines = NULL;
  char buf[1000];
  int i = 0;
  while (fgets(buf, 1000, file)) {
    if(i == arrlen) {
      arrlen += STEPSIZE;
      
      char ** newlines = realloc(lines, arrlen * sizeof(char *));
      if(!newlines) {
        fprintf(stderr, "can't realloc \n");
        exit(1);
      }
      lines = newlines;
    }
    
    // trim off new line char
      buf[strlen(buf) -1] = '\0';
    //Get length of buf
    int slen = strlen(buf);
    
    char *str = (char *)malloc((slen+1) * sizeof(char));
    strcpy(str, buf);
    lines[i] = str;
    i++;
  }
  lines[i] = NULL;
  return lines;
  
}
