//
//  captionLinkedList.c
//  linkedlist
//
//  Created by Kang Jinyeoung on 2017. 1. 28..
//  Copyright © 2017년 Superbderrick. All rights reserved.
//

#include "captionLinkedList.h"


void initCaptionInformationList(captionInfoList* captionList) {
  captionList->count = 0;
  captionList->head = NULL;
}
void deInitCaptionInformationList(captionInfoList * captionList) {
  captionInfo * current = captionList->head;
  captionInfo * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(captionList);
}
void print_captionInformation(captionInfoList* captionList){
  if(captionList != NULL) {
    captionInfo*  tmp=captionList->head;
    printf("startTime : ");
    while(tmp!=NULL){
      printf("%d ",tmp->startTime); // temp only startTme.
      tmp=tmp->next;
    }
    printf("\n");
    printf("Total information count : %d value(s)\n",captionList->count);
  }
  
}
void insertCaptionInformation(captionInfoList* captionList,int startTime,char * captionType,int index){
  if(index<1 || index>(captionList->count)+1){
    printf("Position Out of Bound and overlabed problem \n");
    return;
  }
  captionInfo *  new_captionInfo =(captionInfo*)malloc(sizeof(captionInfo));
  new_captionInfo->startTime=startTime;
  new_captionInfo->languageType = captionType;
  
  if(index==1){
    new_captionInfo->next=captionList->head;
    captionList->head=new_captionInfo;
  }
  else{
    captionInfo*  tmp=captionList->head;
    int i;
    for(i=1;i<index-1;i++){
      tmp=tmp->next;
    }
    new_captionInfo->next=tmp->next;
    tmp->next=new_captionInfo;
  }
  captionList->count++;
}

void deleteCaptionInformation(captionInfoList* captionList,int position){
  //delete an item on the position
  if(position<1 || position>(captionList->count)){
    printf("Position Out of Bound\n");
    return;
  }
  captionInfo*  tmp=captionList->head;
  
  if(position==1){
    captionList->head=tmp->next;
    free(tmp);
  }
  else{
    int i;
    for(i=1;i<position-1;i++){
      tmp=tmp->next;
    }
    captionInfo*  tmp2=tmp->next;
    tmp->next=tmp2->next;
    free(tmp2);
  }
  captionList->count--;
}

int searchCaptionInformation(captionInfoList* captionList,int startTime){
  captionInfo*  tmp=captionList->head;
  int i=1;
  while(tmp!=NULL){
    if(startTime==tmp->startTime) break;
    i++;
    tmp=tmp->next;
  }
  if(i>captionList->count){
    printf("The value %d is NOT exists\n",startTime);
    return 0;
  }
  else{
    printf("The value %d is at position %d in the list\n",startTime,i);
    return i;
  }
}
void insertCaptionText(captionInfoList* captionList,char * captionText,int position){
  if(position<1 || position>(captionList->count)){
    printf("Position Out of Bound\n");
    return;
  }
  captionInfo*  tmp=captionList->head;
  
  int i;
  for(i=1;i<position;i++){
    tmp=tmp->next;
  }
  tmp->captionText=captionText;
}
