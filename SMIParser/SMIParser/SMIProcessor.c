//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"

void showMetaTagInformations(char * strings);

void initProcessor(char ** captionArray) {
  

  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    
   //if you want to get met informations from SMI file please delete comments.
   //showMetaTagInformations(captionArray[i]) ;
    
 
    
    
    
  }
  printf(" Done \n" );
  
}

void showMetaTagInformations(char * strings) {
  const char * passArray[5] = {"<SAMI>" ,"<HEAD>","<TITLE>","<STYLE","</HEAD>"};
  
  //first just pass unessa
  for (int k = 0; k< 5; k++) {
    if(strstr(strings, passArray[k]) != NULL) {
        printf("passtypes %s \n" , strings);
    }
  }
  
};
