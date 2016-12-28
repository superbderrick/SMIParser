//
//  main.c
//  SMIParser
//
//  Created by Kang Jinyeoung on 2016. 12. 26..
//  Copyright © 2016년 SuperbDerrick. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1048576
int test = 0;
int main(int argc, const char * argv[]) {
  
  if (argc != 2) {
    printf("Please input SMIPath correctly ! \n");
    exit(1);
  } else {
    printf("--------------------------------------------- \n");
    printf("Start Parsing AT >>>>>>>>>>>> %s <<<<<<<<<<  \n" , argv[1]);
    printf("--------------------------------------------- \n");
    
    FILE* fin;
    char line[MAX_LENGTH]; /* 라인 문자열을 담들 버퍼 */
    
    
    fin = fopen(argv[1], "r" );
    
    
    if( fin == NULL )
    {
      exit( EXIT_FAILURE );
    }
    
    while( fgets( line, MAX_LENGTH, fin ) )
    {
      test++;
      fputs( line, stdout );
    }
    
    fclose( fin );
    
    
    
    
    
  }
  
  printf("%d\n", test);
  
    return 0;
}
