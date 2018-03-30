#include <stdio.h>

int coln = 1;
int coli = 0;

int ccaComp(const void *p,const void *q){ // stands for 'cascading column-aware comparator'. A comparator function to qsort int-type matrices that iterates across columns until it finds sortable (i.e. different) values
	int *row1 = *((int **)p);
	int *row2 = *((int **)q);

	int diff,i = 0;
	extern int coln; // number of columns to iterate must be declared externally, before calling qsort
	do{
		diff = row1[i]-row2[i];
		
	}while(!diff && ++i<coln);

	return diff;
}

int fcaComp(const void *p,const void *q){ // stands for 'focused column-aware comparator'. A comparator function to qsort int-type matrices according to a specific column
	int *row1 = *((int **)p);
	int *row2 = *((int **)q);

	extern int coli; // column that bases comparison made must be declared externally, before calling qsort
	return row1[coli]-row2[coli];
		
}
