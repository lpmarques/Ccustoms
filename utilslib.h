#ifndef UTILSLIB_H
#define UTILSLIB_H

void checkMemAlloc(void *p);
void writeToFile(char *string, char *filename);
void appendToFile(char *string, char *filename);
void* allocVec(int n,int size);
void* callocVec(int n,int size);
void** allocMat(int m,int n,int size);
void** callocMat(int m,int n,int size);
void freeMat(void **p,int m);
int streq(char *a,char *b);
char* strsect(char *str, int begin, int end);

#endif