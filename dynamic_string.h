typedef struct
{
	unsigned int capacity;
	unsigned int length;
	char *s;
} dynamic_string;

void create_dynamic_string(dynamic_string *ds, char *src);

void free_dynamic_string(dynamic_string *ds);

void reverse(dynamic_string *ds);

void concat(dynamic_string *dst, char *src);

void take(dynamic_string *src, dynamic_string *dst, unsigned int n);

void drop(dynamic_string *src, dynamic_string *dst, unsigned int n);

void filter(dynamic_string *src, dynamic_string *dst, int (*ptr) (char x));

void map(dynamic_string *src, dynamic_string *dst, char (*ptr) (char x));

#ifdef DYNAMIC_STRING_IMPL
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void free_dynamic_string(dynamic_string *ds)
{
	ds->s = NULL;
	free(ds->s);
	ds->length = 0;
	ds->capacity = 0;
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

void concat(dynamic_string *dst, char *src)
{
	unsigned int src_size = (strlen(src) / sizeof(char));
	if(dst->capacity - dst->length < src_size){
	 	 create_dynamic_string(dst, src);
		 return;
	}
	
	strcat(dst->s, src);
	dst->length += src_size;
}

void reverse(dynamic_string *ds)
{
	char copy_s[ds->length];
	for(int i = 0; i < ds->length; i ++){
		copy_s[i] = ds->s[i];
	}
	for(int i = 0; i < ds->length; i ++){
		ds->s[i] = copy_s[ds->length - i - 1];
	}
}

void copy_dynamic_string(dynamic_string *src, dynamic_string *dst)
{
	char copy_s[src->length];
 	strcpy(copy_s, src->s);
	dst->length = src->length;
	dst->capacity = src->capacity;
	dst->s = copy_s;
}

void take(dynamic_string *src, dynamic_string *dst, unsigned int n)
{
	assert(src->length > n);
	copy_dynamic_string(src, dst);
	dst->s[n] = '\0';
	dst->length = n;
}

void print_dynamic_string(dynamic_string *ds)
{
	printf("ds: {capacity: %d, length: %d, s: %s}", ds->capacity, ds->length, ds->s);
}

void filter(dynamic_string *src, dynamic_string *dst, int (*ptr) (char x))
{
	copy_dynamic_string(src,dst);
	int new_length = 0;
	char buffer[src->length];
	for(int i =  0; i < dst->length; i ++)
	{
		int predicate = (*ptr)(src->s[i]);
		if(predicate != 0){
			buffer[new_length] = src->s[i];
			new_length ++;
		}
	}
	dst->s = buffer;
	dst->length = new_length;
}

void drop(dynamic_string *src, dynamic_string *dst, unsigned int n)
{
	copy_dynamic_string(src, dst);
	dst->s = &src->s[n];
	dst->length -= n;
}

void map(dynamic_string *src, dynamic_string *dst, char (*ptr) (char x))
{
	copy_dynamic_string(src, dst);
	char buffer[src->length];
	for(int i = 0; i < dst->length; i ++)
	{
		char c = (*ptr)(src->s[i]);
		buffer[i] = c;
	}
	dst->s = buffer;
	dst->s[dst->length] = '\0';
}
#endif
