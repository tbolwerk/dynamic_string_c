#define DYNAMIC_STRING_IMPL
#include "dynamic_string.h"

int main(int argc, char **argv)
{
	dynamic_string ds;
	create_dynamic_string(&ds, "Hello");
	concat(&ds, ", ");
	concat(&ds, "World!");
	printf("%s", ds.s);
	return 0;
}
