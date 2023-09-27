#include <vector>
#include <iostream>
#include <random>
#include <bitset>

int main() {
	enum wall : unsigned short {north,south,east,west,};
		   //northeast,northwest,southeast,southwest};
	std::vector<std::vector<std::bitset<4>>> maze(10,std::vector<std::bitset<4>>(10,0));		// bitset for each cardinal direction: 0001=N,0010=E,0100=S,1000=W,etc
	std::vector<std::vector<bool>> visitedCells(10,std::vector<bool>(10,false));

	//std::random_device r;
	//std::mt19937 rng(r());
	//std::uniform_int_distribution<std::mt19937::result_type> distribution(0,1);

	for(int columns=0;columns<maze.size();++columns) {
		for(int row=0;row<maze.at(columns).size();++row) {

			std::bitset<4> unvisitedNeighbors;

			try {
				if(!visitedCells.at(columns).at(row-1))
					unvisitedNeighbors.set(wall::north);
			} catch (std::out_of_range const& exception) {}
			try {
				if(!visitedCells.at(columns).at(row+1))
					unvisitedNeighbors.set(wall::south);
			} catch (std::out_of_range const& exception) {}
			try {
				if(!visitedCells.at(columns+1).at(row))
					unvisitedNeighbors.set(wall::east);
			} catch (std::out_of_range const& exception) {}
			try {
				if(!visitedCells.at(columns-1).at(row))
					unvisitedNeighbors.set(wall::west);
			} catch (std::out_of_range const& exception) {
				//std::clog<<"Cell neighbor was beyond edge of unvisitedNeighbors (west): "<<exception.what()<<'\n';
			}
		}
	}

	return 0;
}
