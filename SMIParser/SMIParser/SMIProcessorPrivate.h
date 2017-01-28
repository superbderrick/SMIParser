//
//  SMIProcessorPrivate.h
//  SMIParser
//
//  Created by Kang Jinyeoung on 2017. 1. 28..
//  Copyright © 2017년 SuperbDerrick. All rights reserved.
//

#ifndef SMIProcessorPrivate_h
#define SMIProcessorPrivate_h

#include "captionLinkedList.h"
#include "CaptionDataStrucure.h"

void startProcessing(int i, char **captionArray , captionInfoList * captionList);
int checkStartProcessingPoint(char * strings);
void derrickProcessing(char * strings , captionInformation * info);

#endif /* SMIProcessorPrivate_h */
