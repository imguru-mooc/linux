#if 1
#include <unistd.h>
#include <stdio.h>

#define  a_option  1
#define  l_option  2
#define  i_option  4
#define  R_option  8
// ./a.out -a -liR 

int main(int argc, char **argv)
{
	int opt;
	int flags=0;
	while( (opt = getopt(argc, argv, "aliR" )) != -1 )
	{
		if( opt == 'a' ) flags |= a_option;
		if( opt == 'l' ) flags |= l_option;
		if( opt == 'i' ) flags |= i_option;
		if( opt == 'R' ) flags |= R_option;
	}

	if( flags & a_option ) printf("a option!!\n");
	if( flags & l_option ) printf("l option!!\n");
	if( flags & i_option ) printf("i option!!\n");
	if( flags & R_option ) printf("R option!!\n");
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>

// ./a.out -a -liR 

int main(int argc, char **argv)
{
	int opt;
	while( (opt = getopt(argc, argv, "aliR" )) != -1 )
		;

	// printf("A option!!\n");
	return 0;
}
#endif
