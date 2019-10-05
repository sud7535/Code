#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
  int c=0;
  char file_name[256] = "file.txt";
  char buf[512];
  FILE *f = fopen(file_name, "r");
  srand(time(0)); 
  int n=0,p=0,a[10],l,x=0; 
  for(int l=0;l<10;l++){
    a[l]=rand()%100;
  }
  
  /* for (l=0;l<10;l++){ */
  /*   printf("%d\t",a[l]); */
  /* } */
  l=0;
  while(p<10){
    n=a[l];
    printf("%d",n);
    int lineNumber = 6*n;
    static const char filename[] = "file.txt";
    FILE *file = fopen(filename, "r");
    int count = 0;
    if ( file != NULL )
      {
	char line[256];
	c=lineNumber;
	while(x<61){
	while (fgets(line, sizeof line, file) != NULL)
	  {
	    
	    if (count == lineNumber)
	      {
           
		printf("%s", line);
           	c++;
		if (c >=lineNumber+5){
		break;
		}
	      }
	    else
	      {
		count++;
	      }break;
	  }x++;
	}
	l++;p++;
      }
    fclose(file);
  }
 
  fclose(f);
  
}
