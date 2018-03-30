# Ccustoms

## Description

My utilslib.c and sortslib.c libraries of auxiliary functions for C programming.


## Usage

- Add lines `# include "utilslib.h"` and/or `# include "sortslib.h"` to the headers of your main source code;
- Make sure to place **utilslib.c** and **utilslib.h** (or **sortslib.c** and **sortslib.h**) files in the same directory where you intend to compile the source code;
- Include utilslib.c and/or sortslib.c when compiling your code (e.g. `gcc -o my_exec my_main.c utilslib.c sortslib.c`).


## utilslib.c

A set of miscelanious functions that facilitate memory allocation, string manipulation and more.

### checkMemAlloc()

prototype: `void checkMemAlloc(void *p);`

Checks memory allocation for any pointer **\*p** given as input. If allocation was successful, it does nothing. Otherwise, it prints the memory allocation error and terminates the program.

### writeToFile()

prototype: `void writeToFile(char *string, char *filename);`

Straight-forward way to write text to file. Automatically opens FILE pointer, prints out string's content and closes it back.

### appendToFile()

prototype: `void appendToFile(char *string, char *filename);`

Same as writeToFile() but appends string's content to the end of file, instead of overwriting any previously existing content.

### allocVec()

prototype: `void* allocVec(int n,int size);`

Uses stdlib's malloc() to allocate memory for **n** elements of same **size**, automatically checking if allocation worked. Returns a pointer to the base address of the allocated range. Can be used to allocate memory for a vector of size **n**.

### callocVec()

prototype: `void* callocVec(int n,int size);`

Same as allocVec() but uses stdlib's calloc() instead of malloc() (all bits in allocated range are automatically set to 0).

### allocMat()

prototype: `void** allocMat(int m,int n,int size);`

Uses stdlib's malloc() to allocate memory for **m** pointers to base addresses of **n** elements of same **size** each. Returns a pointer to the base address of the **m** pointers. Can be used to allocate memory for a matrix of size **m**x**n**.

### callocMat()

prototype: `void** callocMat(int m,int n,int size);`

Same as allocMat() but uses stdlib's calloc() instead of malloc() (all bits in allocated ranges are automatically set to 0).

### freeMat()

prototype: `void freeMat(void **p,int m);`

Provided a pointer to pointer **\*\*p**, recursivelly frees all memory allocated for the set of **m** pointers it points to and for the corresponding addresses each of these point to. Useful to deallocate memory used for a matrix.

### streq()

prototype: `int streq(char *a,char *b);`

Compares any two strings **a** and **b** and returns 1 if they are identical or 0 otherwise.

### strsect()

prototype: `char* strsect(char *str,int begin,int end);`

Provided a pointer to a string (**\*str**), returns a pointer to a substring of it. This substring will equal the section of the original one that ranges from index **begin** to index **end**.


## sortslib.c

A couple of user-defined comparator functions to be used together with stdlib's qsort function.

### ccaComp

prototype: `int ccaComp(const void *p,const void *q);`

Stands for 'cascading column-aware comparator'. A comparator function that allows sorting all rows in an int-type matrix in a cascading fashion: if two elements in the first column are equal, ccaComp will try to sort their rows according to elements in second column and so on.

**Beware:** The number of in-matrix columns ccaComp will be aware of (from first up to the last one) must be user-assigned to an int-type **coln** variable *before* calling qsort, like in:
```c
int rown = 15;
int coln = 10; // for a matrix of size 15x10
qsort(ptomatrix,rown,sizeof(int),ccaComp);
```
If not declared, **coln** will default to 1 and qsort will sort all rows according to the first column only.

### fcaComp

prototype: `int fcaComp(const void *p,const void *q);`

Stands for 'focused column-aware comparator'. A comparator function that allows sorting all rows in an int-type matrix according to a specific column. The index of the column fcaComp will focus on must be user-assigned to an int-type **coli** variable *before* calling qsort, like in:
```c
int rown = 15;
int coli = 5; // to sort all 15 rows according to the sixth column
qsort(ptomatrix,rown,sizeof(int),fcaComp);
```
In case **coli** is not declared it will default to 0 and qsort will sort all rows according to the first column.
