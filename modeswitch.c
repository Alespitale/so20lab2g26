#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	if(argc != 2) {
		printf(1, "Usage: modeswitch 1 o 0\n");
	}else {
		modeswitch(atoi(argv[1]));
	}

	exit();
}
