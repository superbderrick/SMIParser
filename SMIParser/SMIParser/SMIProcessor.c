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
  int num ,second ;
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    if(i ==0) {
     num = strcmp(test, captionArray[i]);
     printf("num %d \n" , num);
     
      second = strcmp("<SAMI>", &captionArray[0][0]);
      printf("num %d \n" , second);
    }
    
    
    
    
  }
  printf(" Done \n" );
  
}

