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
  for (int i = 0 ; captionArray[i] != NULL ; i++) {
    printf("%s\n" ,captionArray[i]);
  }
  printf(" Done \n" );
  
}
