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
  char buf[LINEBYBUFFERMAXIMUMSIZE];
  int i = 0;
  while (fgets(buf, LINEBYBUFFERMAXIMUMSIZE, file)) {
    if(i == arrlen) {
      arrlen += STEPSIZE;
      
      char ** newlines = realloc(lines, arrlen * sizeof(char *));
      if(!newlines) {
        printf("can't realloc \n");
        exit(1);
      }
      lines = newlines;
    }
    
    //excaption work for Carrage Return Handle
    
    if(buf[strcspn(buf, CARRAGE_RETURN)] == strlen(buf)) {
       buf[strlen(buf) -1] = NULL_CHAR;
    } else
      buf[strcspn(buf,CARRAGE_RETURN)] = 0;
    
    unsigned long slen = strlen(buf);
    
    char *str = (char *)malloc((slen+1) * sizeof(char));
    strcpy(str, buf);
    lines[i] = str;
    i++;
  }
  lines[i] = NULL;
  
  return lines;
  
}
