#include "play.h"

int main(int argc, char **argv){
    play *p = new play();
    p->execute();
	delete p;
	return 0;
}
