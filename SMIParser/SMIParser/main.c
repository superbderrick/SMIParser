//
//  main.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 26..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
  
  if (argc != 2) {
    printf("Please input SMIPath correctly ! \n");
    exit(1);
  } else {
    printf("--------------------------------------------- \n");
    printf("Start Parsing AT >>>>>>>>>>>> %s <<<<<<<<<<  \n" , argv[1]);
    printf("--------------------------------------------- \n");
    
    
  }
    
  
  
    return 0;
}
