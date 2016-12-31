//
//  main.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 26..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ParserConfig.h"
#include "ErrorType.h"
#include "SMIParser.h"

int checkArgument(int num ,const char* fileName);

int main(int argc, const char * argv[]) {
  
  if(checkArgument(argc, argv[1]) == 0)
    readFile(argv[1]);
  
    return 0;
}

int checkArgument(int num , const char * fileName) {
  int errorNone = 0;
  
  if (num != ARGUMENT_NUM) {
    errorNone = 1;
    printf("Please input SMIPath correctly ! \n");
    exit(1);
  } else {
    errorNone = 0;
    printf("--------------------------------------------- \n");
    printf("Start Parsing AT >>>>>>>>>>>> %s <<<<<<<<<<  \n" , fileName);
    printf("--------------------------------------------- \n");
    
  }
  
  return errorNone;
  
}
