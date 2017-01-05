//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"



void init(char ** captionArray) {
  printf(" Init success \n" );
  
  //, "<STYLE", "<!--", "P {","-->" ,"<--" ,"</STYLE>"
  const char* const passTagsArray[] = {"<SAMI>", "<HEAD>"};
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    
    
   // printf("%s\n" ,captionArray[i]);
    
    for (int k = 0; k< 2; k++) {
      if(strcmp(captionArray[i], passTagsArray[k]) == 0) {
        
        printf("%s", captionArray[i]);
        break;
      } else {
        //printf("start");
      }
      
    }
    
//    if(strcmp(captionArray[i], passTagsArray)) {
//      
//    }
  }
  printf(" Done \n" );
  
}

