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
    
    //read whole file and receive caption's information array.
    char ** captionLines = readFile(argv[1]);
    
    if(!captionLines) {
      printf("File read failuer it didin't make wordsList \n");
      exit(1);
    } else {
      initProcessor(captionLines);
      
    }
    
    free(captionLines);
    
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
    printf("Invalid arguments error Please input Filepath correctly ! \n");
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
