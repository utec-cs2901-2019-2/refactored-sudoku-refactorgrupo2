#include <iostream>
#include <vector>
#include <random>

constexpr unsigned int SIZE = 9;

using namespace std;

class sudoku {
	public:
		sudoku() {
			for (int i = 0; i < SIZE; ++i) {
				table.resize(SIZE);
				for (int j = 0; j < SIZE; ++j)
					table[i].resize(SIZE);
			}
		}

		void generate() {
			srand(time(NULL));
			for(int i = 0; i < SIZE; ++i){
				for(int j = 0; j < SIZE; ++j){
					if (rand() % 3 == 0) {
							table[i][j] = rand() % 9;
					}
				}
			}
		}

		void insert (int x, int y, int value) {
			table[x][y] = value;
		}

		void display () {
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					cout << table[i][j] << " ";
					if (j % 3 == 2) cout << "\t|\t";
				}
				cout << endl;
			}
		}

		bool validateRow() {
			vector<int> presentNumbers;
			for (int i = 0; i < SIZE; ++i) {
				presentNumbers.clear();
				presentNumbers.resize(SIZE);
				for (int j = 0; j < SIZE; ++j) {
					if (table[i][j] == 0) return false;			
					if (presentNumbers[table[i][j] - 1] == 1) return false;
					presentNumbers[table[i][j] - 1] = 1;
				}
				for (int j = 0; j < SIZE; ++j)
					if (presentNumbers[j] != 1) return false;
			}
			return true;
		}


		bool validateColumn() {
			vector<int> presentNumbers;
			for (int i = 0; i < SIZE; ++i) {
				presentNumbers.clear();
				presentNumbers.resize(SIZE);
				for (int j = 0; j < SIZE; ++j) {
					if (table[j][i] == 0)
						return false;	
					if (presentNumbers[table[j][i] - 1] == 1)
						return false;
					presentNumbers[table[j][i] - 1] = 1;
				}
				for (int j = 0; j < SIZE; ++j)
					if (presentNumbers[j] != 1)
						return false;
			}
			return true;
		}

		bool validateSquares() {
			int sizeX, sizeY;
			vector<int> presentNumbers;
			for (int k = 0; k < SIZE; ++k) {
				presentNumbers.empty();
				presentNumbers.resize(SIZE);
				sizeX = 0;
				sizeY = 0;
				if (k % 3 == 0) 
					sizeX = 3;
				if (k % 3 == 1)
					sizeX = 6;
				if (k > 2)
					sizeY = 3;
				if (k > 5)
					sizeY = 6;

				for (int i = 0; i < 3; ++i){
					for (int j = 0; j < 3; ++j) {
						if (table[i][j] == 0)
							return false;	
						if (presentNumbers[table[i + sizeY][j + sizeX] - 1] == 1)
							return false;
						presentNumbers[table[i+ sizeY][j + sizeX] - 1] = 1;
					}
				}
			}
			return true;
		}

		bool checkWin () {

			if (!validateRow() || !validateColumn())
				return false;
		
			if (!validateSquares())
				return false;

			return true;
		}

	private:
		std::vector<vector<int>> table;
};
