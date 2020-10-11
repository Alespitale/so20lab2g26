#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	if(argc != 4) {
		printf(1, "Usage: plotpixel -x -y -color\n");
	}else {
		plotpixel(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	}

	exit();
}
