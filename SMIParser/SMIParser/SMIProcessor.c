//
//  SMIProcessor.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 1..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#include "SMIProcessor.h"
#include "CaptionDataStrucure.h"

int checkStartProcessingPoint(char * strings);
void startProcessing(char * strings , captionInformation * info);

captionInformation* getStartTime(char * strings , captionInformation * info);

int captionStatus = CAPTION_READY;

void checkEntryPoint(int *processingStatus_p, int i, char **captionArray) {
    //showMetaTagInformations(captionArray[i]) ;
   
      if(*processingStatus_p == NOT_YET) {
      if(checkStartProcessingPoint(captionArray[i]) == SEEK_BODY_TAG) {
        *processingStatus_p = SEEK_BODY_TAG;
      } else if (captionArray[i] == NULL) {
        *processingStatus_p = NOTHING_BODY_TAG;
      }else {
        *processingStatus_p = NOT_YET;
      }
    }
}

void analzecaptiondata(int processingStatus, int i, char **captionArray) {
  if(processingStatus == NOT_YET) {
      return;
    } else if(processingStatus == SEEK_BODY_TAG) {
      captionInformation * info;
      startProcessing(captionArray[i] , info);
    } else if(processingStatus == NOTHING_BODY_TAG) {
      printf("UnSupportType ,it can't looking for <BODY> Tag  \n");
      exit(1);
    }
}

void initProcessor(char ** captionArray) {
  int processingStatus = NOT_YET;
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    checkEntryPoint(&processingStatus, i, captionArray);
    
    analzecaptiondata(processingStatus, i, captionArray);
    
  }
  printf("ProcessingDone \n" );
  
}

captionInformation* getStartTime(char * strings ,captionInformation * info) {
  char *ptr;
  int i = 0;
  while(ptr != NULL ){
    if(i == 0) {
      ptr = strtok(strings, "=");
      printf( "%s\n" , ptr);
      ptr = strtok(NULL, ">");
      info->startTime = atoi(ptr);
      printf( "%s\n" , ptr);
    } else if(i == 1) {
      ptr = strtok(NULL, "=");
      printf( "%s\n" , ptr);
      ptr = strtok(NULL, ">");
      printf( "%s\n" , ptr);
      info->languageType = ptr;
      ptr = NULL;
      break;
    }
    i++;
  }
  
  return info;
}


void startProcessing(char * strings ,captionInformation * info) {
  printf("test line by line %s \n" , strings );
  const static char * startPart = "<SYNC Start=";
  
//  if(captionStatus == CAPTION_READY) {
//    if(strstr(strings, startPart) != NULL) {
//      captionStatus = CAPTION_MAKING;
//      
//      
//      info = getStartTime(strings , info);
//      
//    }
//  } else if(captionStatus == CAPTION_MAKING) {
//    char *pptr;
//    int k = 0;
//    
////    while(pptr != NULL ){
////      if(k == 0) {
////        pptr = strtok(strings, "=");
////        printf( "%s\n" , pptr);
////        pptr = strtok(NULL, ">");
////        info.fontColor = pptr;
////        printf( "%s\n" , pptr);
////      } else if(k == 1) {
////        pptr = strtok(NULL, "<");
////        printf( "%s\n" , pptr);
////        info.captionText = pptr;
////        break;
////      }
////      
////      k++;
////    }
//    
//  } else if (captionStatus == CAPTION_COMPLETE) {
//    
//  }
//  
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
