#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef struct
{
	unsigned int capacity;
	unsigned int length;
	char *s;
} dynamic_string;

void free_dynamic_string(dynamic_string *ds)
{
	ds->s = NULL;
	free(ds->s);
	ds = NULL;
	free(ds);
}

void create_dynamic_string(dynamic_string *ds,  char *src)
{
	ds->length += strlen(src);
	ds->capacity = ds->length * 2;
	if(ds->s == NULL)
	{
		ds->s = malloc(ds->capacity);
		strcpy(ds->s, src);
		return;
	}
	ds->s = realloc(ds->s, ds->capacity * sizeof(char));
	ds->s = strcat(ds->s, src); 
}

void concat(dynamic_string *dst, char *src){
	unsigned int src_size = (strlen(src) / sizeof(char));
	if(dst->capacity - dst->length < src_size){
	 	 create_dynamic_string(dst, src);
		 return;
	}
	
	strcat(dst->s, src);
	dst->length += src_size;
}


int main(int argc, char **argv)
{
	dynamic_string ds;
	create_dynamic_string(&ds, "Hello");
	concat(&ds, ",");	
	concat(&ds, " ");	
	concat(&ds, "W");
	concat(&ds, "o");
	concat(&ds, "r");	
	concat(&ds, "l");	
	concat(&ds, "d");	
	concat(&ds, "!");	
	concat(&ds, "\n");	
	printf("result: %s", ds.s);
	free_dynamic_string(&ds);	
	create_dynamic_string(&ds, "My name is:");
	concat(&ds, " Twan");
	printf("%s", ds.s);
	return 0;
}


