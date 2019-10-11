#include "sudoku.h"

class play {
public:
	sudoku *s;

	play() {
		s =  new sudoku();
		s->generate();

	
	}


	void execute () {
		int x, y, value;
		while(1){
			s->display();
			std::cin>>x>>y>> value;
			s->insert(x, y, value);
			if (s->checkWin()) break;
		}
	}	

};

