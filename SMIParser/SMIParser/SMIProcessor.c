//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"


int captionStatus = CAPTION_READY;

void checkBodyTag(int *processingStatus_p, int i, char **captionArray) {
      if(*processingStatus_p == NOT_YET) {
        if(checkStartProcessingPoint(captionArray[i]) == SEEK_BODY_TAG) {
          *processingStatus_p = SEEK_BODY_TAG;
        } else if (captionArray[i] == NULL) {
          *processingStatus_p = NOTHING_BODY_TAG;
        } else {
        *processingStatus_p = NOT_YET;
      }
    }
}

void startProcessing(int i, char **captionArray , captionInfoList * captionList) {
    derrickProcessing(captionArray[i] , captionList ,i);
}

void initProcessor(char ** captionArray) {
  int processingStatus = NOT_YET;
  captionInfoList * captioninfoList = (captionInfoList *)malloc(sizeof(captionInfoList));
  initCaptionInformationList(captioninfoList);
  
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    checkBodyTag(&processingStatus, i, captionArray);
    
    if(processingStatus == SEEK_BODY_TAG)
        startProcessing( i, captionArray , captioninfoList);
  }
    printf("ProcessingDone \n" );
}




void derrickProcessing(char * strings ,captionInfoList * captionList ,int index) {
  printf("test line by line %s \n" , strings );
  const static char * startPart = "<SYNC Start=";
  
  if(captionStatus == CAPTION_READY) {
    if(strstr(strings, startPart) != NULL) {
      char *ptr;
      int i = 0;
      int startTime = 0;
      char * languageType;
      
      while(strings != NULL ){
        if(i == 0) {
          ptr = strtok(strings, "=");
          printf( "%s\n" , ptr);
          ptr = strtok(NULL, ">");
          startTime = atoi(ptr);
          printf( "%s\n" , ptr);
        } else if(i == 1) {
          ptr = strtok(NULL, "=");
          printf( "%s\n" , ptr);
          ptr = strtok(NULL, ">");
          printf( "%s\n" , ptr);
          languageType = ptr;
          ptr = NULL;
          break;
        }
        i++;
      }
      captionStatus = CAPTION_MAKING;
      insertCaptionInformation(captionList, startTime, languageType,i -(i-1));
    }
  } else if(captionStatus == CAPTION_MAKING) {
    char *pptr;
    int k = 0;
    while(strings != NULL ){
      if(k == 0) {
        pptr = strtok(strings, "=");
        //printf( "%s\n" , pptr);
        pptr = strtok(NULL, ">");
        //printf( "%s\n" , pptr);
      } else if(k == 1) {
        pptr = strtok(NULL, "<");
        printf( "%s\n" , pptr);
        insertCaptionText(captionList, pptr, 1);
        break;
      }
      
      k++;
    }
    captionStatus = CAPTION_COMPLETE;
    
  } else if (captionStatus == CAPTION_COMPLETE) {
    char *ptr;
    int i = 0;
    int startTime = 0;
    char * languageType;
    
    while(strings != NULL ){
      if(i == 0) {
        ptr = strtok(strings, "=");
        printf( "%s\n" , ptr);
        ptr = strtok(NULL, ">");
        startTime = atoi(ptr);
        printf( "%s\n" , ptr);
      } else if(i == 1) {
        ptr = strtok(NULL, "=");
        printf( "%s\n" , ptr);
        ptr = strtok(NULL, ">");
        printf( "%s\n" , ptr);
        languageType = ptr;
        ptr = NULL;
        break;
      }
      i++;
    }
    
  }
  
}

int checkStartProcessingPoint(char * strings ) {
  const static char * bodyTag = "<BODY>";
  int hasBodyTag = ERROR_NONE;
  if(strstr(strings, bodyTag) != NULL) {
    hasBodyTag = SEEK_BODY_TAG;
  } else
    hasBodyTag = NOTHING_BODY_TAG;

    return hasBodyTag;
}

void showMetaTagInformations(char * strings) {
  const char * passArray[5] = {"<SAMI>" ,"<HEAD>","<TITLE>","<STYLE","</HEAD>"};
  
  for (int k = 0; k< 5; k++) {
    if(strstr(strings, passArray[k]) != NULL) {
        printf("passtypes %s \n" , strings);
    }
  }
  
};
