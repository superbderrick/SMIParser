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
  const char * passArray[5] = {"<SAMI>" ,"<HEAD>","<TITLE>","<STYLE","</HEAD>"};

  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    printf("realType %s \n" , captionArray[i]);
    
    for (int k = 0; k< 5; k++) {
      if(strstr(captionArray[i], passArray[k]) != NULL) {
        printf("passtypes %s \n" , captionArray[i]);
      }
    }
    
    //      if(strcmp(captionArray[i], passArray[k]) == 0) {
    //        printf("you did %s \n" , captionArray[i]);
    //
    //      }

    
    
    
  }
  printf(" Done \n" );
  
}

