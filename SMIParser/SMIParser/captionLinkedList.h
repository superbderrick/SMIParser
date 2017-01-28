//
//  captionLinkedList.h
//  linkedlist
//
//  Created by Kang Jinyeoung on 2017. 1. 28..
//  Copyright © 2017년 Superbderrick. All rights reserved.
//

#ifndef captionLinkedList_h
#define captionLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct captionInfo {
  unsigned int startTime;
  unsigned int endTime;
  char * languageType;
  char * captionText;
  struct captionInfo * next;
} captionInfo;

typedef struct captionInfoList {
  int count;
  captionInfo * head;
} captionInfoList;

void initCaptionInformationList(captionInfoList* captionList);
void insertCaptionInformation(captionInfoList* captionList,int startTime,int index);
void deleteCaptionInformation(captionInfoList* captionList,int position);
void print_captionInformation(captionInfoList* captionList);
void updateCaptionInfo(captionInfoList* captionList,int startTime,int position);
void deInitCaptionInformationList(captionInfoList* captionList);
void searchCaptionInformation(captionInfoList* captionList,int startTime);


#endif /* captionLinkedList_h */
