//
//  CaptionDataStrucure.h
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 15..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#ifndef CaptionDataStrucure_h
#define CaptionDataStrucure_h

typedef struct captionInformation {
  int startTime;
  int endTime;
  char * fontColor;
  char * languageType;
  char ** captionText;
  
} captionInformation;


#endif /* CaptionDataStrucure_h */
