#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void checkMemAlloc(void *p){
	if(p == NULL){
		perror("Fail");
		exit(1);
	}
}

void writeToFile(char *string, char *filename){
	FILE *fh = fopen(filename,"w");
	checkMemAlloc(fh);

	fprintf(fh,"%s",string);
	fclose(fh);
}

void appendToFile(char *string, char *filename){
	FILE *fh = fopen(filename,"a");
	checkMemAlloc(fh);

	fprintf(fh,"%s",string);
	fclose(fh);
}

void* allocVec(int n,int size){
	void *p;
	p = malloc(n*size);
	checkMemAlloc(p);
	return p;
}

void* callocVec(int n,int size){
	void *p;
	p = calloc(n,size);
	checkMemAlloc(p);
	return p;
}

void** allocMat(int m,int n,int size){
	void **p;
	p = malloc(m*sizeof(*p));
	checkMemAlloc(p);
	for(int i=0;i<m;i++)
		p[i] = allocPointer(n,size);
	return p;
}

void** callocMat(int m,int n,int size){
	void **p;
	p = calloc(m,sizeof(*p));
	checkMemAlloc(p);
	for(int i=0;i<m;i++)
		p[i] = callocPointer(n,size);
	return p;
}

void freeMat(void **p,int m){
	for(int i=0;i<m;i++)
		free(p[i]);
	free(p);
}

int streq(char *a,char *b){
	for(int i=0;1;i++)
		if(a[i] != b[i])
			return 0;
		else if(a[i] == '\0')
			return 1;
}

char* strsect(char *str,int begin,int end){
	if(end<begin){
		printf("strsub: End of substring must come after its beginning 'strsect(str,begin,end)'\n");
		exit(1);
	}

	char* substr;
	int len = end-begin+1;
	substr = allocPointer(len+1,sizeof(*substr));
	memcpy(substr,str+begin,len);
	substr[len] = '\0';

	return substr;
}