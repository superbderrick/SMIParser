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
  int processingStatus = NOT_YET;
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    //if you want to get met informations from SMI file please delete comments.
    //showMetaTagInformations(captionArray[i]) ;
   
    if(processingStatus == NOT_YET) {
      if(checkStartProcessingPoint(captionArray[i]) == SEEK_BODY_TAG) {
        processingStatus = SEEK_BODY_TAG;
      } else if (captionArray[i] == NULL) {
        processingStatus = NOTHING_BODY_TAG;
      }else {
        processingStatus = NOT_YET;
      }
    }
    
    if(processingStatus == NOT_YET) {
      continue;
    } else if(processingStatus == SEEK_BODY_TAG) {
      startProcessing(captionArray[i]);
    } else if(processingStatus == NOTHING_BODY_TAG) {
      printf("UnSupportType ,it can't looking for <BODY> Tag  \n");
      exit(1);
    }
    
    
    
  }
  printf("ProcessingDone \n" );
  
}

void startProcessing(char * strings) {
  printf(" Strings %s \n" ,strings );
}

int checkStartProcessingPoint(char * strings ) {
  const static char * startTag = "<BODY>";
  int hasBodyTag = ERROR_NONE;
  if(strstr(strings, startTag) != NULL) {
    hasBodyTag = SEEK_BODY_TAG;
  } else
    hasBodyTag = NOTHING_BODY_TAG;

    return hasBodyTag;
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
