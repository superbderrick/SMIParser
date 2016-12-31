//
//  SMIParser.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 31..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include "SMIParser.h"

int test = 0;

void readFile(const char * path) {
  
  FILE* file;
  char line[MAX_LENGTH];
  
  file = fopen(path, "r");
  
  
  if(file == NULL)
    exit( EXIT_FAILURE );
  
  while( fgets( line, MAX_LENGTH, file ) )
  {
    test++;
   // fputs( line, stdout );
  }
  
  fclose( file );
  printf("Line Num : %d \n" , test);
}
