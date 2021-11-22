#define DYNAMIC_STRING_IMPL
#include "dynamic_string.h"
#include <ctype.h> 
#include <stdbool.h>

char all_caps(char x){
	return toupper(x);
}

char my_map(char x)
{
	if (x == '6')
	{
		return '0';
	}
	return '1';
}

int my_func(char x){
	int dx = atoi(&x);
	if(dx % 2 == 0)
	{
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	dynamic_string ds = {};
	create_dynamic_string(&ds, "Hello");

	concat(&ds, ", ");
	concat(&ds, "World!");
	printf("%s\n", ds.s);
	concat(&ds, "This is a demo, giving an example on how to use this library");
	printf("%s\n", ds.s);
	free_dynamic_string(&ds);

	create_dynamic_string(&ds, "new");\
	printf("length: %d\n", ds.length);
	reverse(&ds);
	dynamic_string ds2 = {};	
	take(ds, &ds2,2);	
	printf("%s\n", ds2.s);
	printf("%s\n", ds.s);

	dynamic_string filter_ds = {};
	create_dynamic_string (&filter_ds, "123456789");
	printf("%s\n", filter_ds.s);
	dynamic_string ds3 = {};
	
	filter(filter_ds, &ds3, my_func);	
	printf("filter:%s\n", ds3.s);
	printf("filter:%s\n", filter_ds.s);
	dynamic_string ds4 = {};
	drop(filter_ds, &ds4, 5);

	take(ds4, &ds4, 1);
	printf("%s\n", ds4.s);

	dynamic_string ds5 = {};
	map(filter_ds, &ds5, my_map);
	printf("%d\n", filter_ds.length);
	printf("input: %s", ds5.s);

	dynamic_string in_and_out = {};
	create_dynamic_string(&in_and_out, "This is a test!");
	map(in_and_out, &in_and_out, all_caps);
	print_dynamic_string(&in_and_out);

	return 0;
}
