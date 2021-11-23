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

int just_twan(char x){
	switch (x)
	{
	case 'T':
		return true;
	case 'W':
		return true;
	case 'A':
		return true;
	case 'N':
		return true;
	default:
		return false;
	}
}

int main()
{
	dynamic_string ds = {};

	create_dynamic_string(&ds, "The quick brown fox jumps over the lazy dog");
	print_dynamic_string(&ds);

	map(&ds, all_caps);
	print_dynamic_string(&ds);

	dynamic_string twan = {};
	create_dynamic_string(&twan, "");
	filter(ds, &twan, just_twan);
	print_dynamic_string(&twan);

	filter(ds, &ds, no_spaces);
	print_dynamic_string(&ds);
	
	sort(ds, &ds);
	print_dynamic_string(&ds);


	dynamic_string abc = {};
	take(ds, &abc, 3);
	print_dynamic_string(&abc);

	dynamic_string xyz = {};
	drop(&xyz, 32);
	print_dynamic_string(&xyz);

	free_dynamic_string(&xyz);

	reverse(ds, &ds);	
	take(ds, &xyz, 3);
	print_dynamic_string(&xyz);

	reverse(xyz, &xyz);	
	print_dynamic_string(&xyz);
	

	return 0;
}

