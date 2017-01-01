//
//  main.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 26..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include <stdio.h>

#include "ErrorType.h"
#include "SMIParser.h"
#include "SMIProcessor.h"
int checkArgument(int num ,const char* fileName);
void startParsing(const char * fileName);

int main(int argc, const char * argv[]) {
  
  // check whether correct arguments.
  if(checkArgument(argc, argv[1]) == ERROR_NONE) {
    startParsing(argv[1]);
    
    char ** words = readFile(argv[1]);
    
    if(!words) {
      printf("Can't build Data Strucure \n");
      exit(1);
    } else {
      init(words);
    }
    
  } else {
    printf("Input arguments error program finish. \n");
    exit(1);
  }
  
    return 0;
}



int checkArgument(int num , const char * fileName) {
  int errorNone = ERROR_NONE;
  
  if (num != ARGUMENT_NUM) {
    errorNone = ERROR_OCCUR;
    printf("Please input SMIPath correctly ! \n");
    exit(1);
  } else {
    errorNone = ERROR_NONE;
  }
    return errorNone;
}

void startParsing(const char * fileName) {
  printf("---------------------------------------------\n");
  printf("Start Parsing AT >>>>>>>>> %s <<<<<<<<<\n" , fileName);
  printf("---------------------------------------------\n");
}
