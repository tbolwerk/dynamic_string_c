#define DYNAMIC_STRING_IMPL
#include "dynamic_string.h"

#include <stdbool.h>


int my_func(char x){
	int dx = atoi(&x);
	if(dx < 5)
	{
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	dynamic_string ds;
	create_dynamic_string(&ds, "Hello");

	concat(&ds, ", ");
	concat(&ds, "World!");
	printf("%s\n", ds.s);
	concat(&ds, "This is a demo, giving an example on how to use this library");
	printf("%s\n", ds.s);
	free_dynamic_string(&ds);

	
	create_dynamic_string(&ds, "new");
	printf("length: %d\n", ds.length);
	reverse(&ds);
	dynamic_string ds2;	
	take(&ds, &ds2,2);	
	printf("%s\n", ds2.s);
	printf("%s\n", ds.s);

	dynamic_string filter_ds;
	create_dynamic_string (&filter_ds, "123456789");
	printf("%s\n", filter_ds.s);
	dynamic_string ds3;
	
	filter(&filter_ds, &ds3, my_func);	
	printf("filter:%s\n", ds3.s);

	return 0;
}
