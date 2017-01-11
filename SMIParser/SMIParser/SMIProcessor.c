//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"


void initProcessor(char ** captionArray) {
  printf(" Init success \n" );
  char * test = "<SAMI>";
  
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    if(i ==0) {
      if(strcmp(captionArray[i], test) == 0) {
        printf("you did \n");
      }
    }
    
    
    
  }
  printf(" Done \n" );
  
}

