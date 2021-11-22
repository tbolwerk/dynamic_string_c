#define DYNAMIC_STRING_IMPL
#include "dynamic_string.h"
#include <ctype.h> 
#include <stdbool.h>

char all_caps(char x){
	return toupper(x);
}

int no_spaces(char x){
	return x != ' ';
}

int main()
{
	dynamic_string ds = {};

	create_dynamic_string(&ds, "The quick brown fox jumps over the lazy dog");
	print_dynamic_string(&ds);

	map(ds, &ds, all_caps);
	print_dynamic_string(&ds);

	filter(ds, &ds, no_spaces);
	print_dynamic_string(&ds);
	
	sort(ds, &ds);
	print_dynamic_string(&ds);


	dynamic_string abc = {};
	take(ds, &abc, 3);
	print_dynamic_string(&abc);

	dynamic_string xyz = {};
	drop(ds, &xyz, 32);
	print_dynamic_string(&xyz);

	return 0;
}

