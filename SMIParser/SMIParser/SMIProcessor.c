//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"

int checkStartProcessingPoint(char * strings);
void startProcessing(char * strings);

void initProcessor(char ** captionArray) {
  int bStart = NOT_YET;
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    
  //if you want to get met informations from SMI file please delete comments.
  //showMetaTagInformations(captionArray[i]) ;
   
    if(bStart == NOT_YET) {
      if(checkStartProcessingPoint(captionArray[i]) == ERROR_NONE) {
        bStart = SUCCESS;
      } else if (captionArray[i] == NULL) {
        bStart = FAILURE;
      }else {
        bStart = NOT_YET;
      }
    }
    
    if(bStart == NOT_YET) {
      continue;
    } else if(bStart == SUCCESS) {
      startProcessing(captionArray[i]);
    } else if(bStart == FAILURE) {
      printf("UnSupportType ,it can't looking for <BODY> Tag  \n");
      exit(1);
    }
    
    
    
  }
  printf(" Done \n" );
  
}

void startProcessing(char * strings) {
  printf(" Strings %s \n" ,strings );
}

int checkStartProcessingPoint(char * strings ) {
  const static char * startTag = "<BODY>";
  int bFound = ERROR_NONE;
  if(strstr(strings, startTag) != NULL) {
    bFound = SUCCESS;
  } else
    bFound = FAILURE;

    return bFound;
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
