#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Return line count, but stop once the count exceeds a maximum
int Line_Count(FILE *istream, int line_index) {
	  int lc = 0;
	    int previous = '\n';
	      int ch;
	        rewind(istream);
		  while (line_index > 0 && (ch = fgetc(istream)) != EOF) {
			      if (ch == '\n') {
				            line_index--;
					        }
						    if (previous == '\n') {
							          lc++;
								      }
								          previous = ch;
									    }
									      return lc;
}

void print_random_line(FILE *istream, int line_index) {
	  printf("%8d: <", line_index + 1);
	    Line_Count(istream, line_index);
	      int ch;
	        while ((ch = fgetc(istream)) != EOF && ch != '\n') {
			    if (isprint(ch)) {
				          putchar(ch);
					      }
					        }
						  printf(">\n");
}

int main() {
	  srand((unsigned) time(NULL));
	    FILE *istream = fopen("test.txt", "r");
	      assert(istream);
	        int lc = Line_Count(istream, RAND_MAX);
		  assert(lc && lc < RAND_MAX);
		    for (int i = 0; i < 10; i++) {
			        print_random_line(istream, rand() % lc);
				  }
				    fclose(istream);
}
