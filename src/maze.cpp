#include <maze.h>
#include <vector>
#include <iostream>
#include <random>
#include <bitset>
#include <cmath>

namespace maze {
	generator::generator() {
		const unsigned short DIRECTIONS=4;
		const int MAZE_SIZE=10;
		enum wall : unsigned short {north,south,east,west,
			   northeast,northwest,southeast,southwest,
			   north_northeast,east_northeast,north_northwest,west_northwest,south_southeast,east_southeast,south_southwest,west_southwest};
		std::vector<std::vector<std::bitset<DIRECTIONS>>> mazeWalls(MAZE_SIZE,std::vector<std::bitset<DIRECTIONS>>(MAZE_SIZE,0));
		std::vector<std::vector<bool>> visitedCells(MAZE_SIZE,std::vector<bool>(MAZE_SIZE,false));

		std::random_device r;
		std::mt19937 rng(r());
		//rng.seed(1024);
		
		std::uniform_int_distribution<std::mt19937::result_type> distribution(0,std::pow(2,mazeWalls.at(0).at(0).size())-1);		// generate num from 0 to 2^(amount of bits used in the bitset) minus 1 (since a full 1111 bitset is 15, not 16)

		for(int columns=0;columns<mazeWalls.size();++columns) {
			for(int row=0;row<mazeWalls.at(columns).size();++row) {

				mazeWalls.at(columns).at(row)=distribution(rng);

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

				std::cout<<mazeWalls.at(columns).at(row)<<" ";

				//if(unvisitedNeighbors.any()) {
				//	wall nextCell;
				//	do {
				//		nextCell=std::uniform_int_distribution<std::mt19937::result_type> distribution(0,unvisitedNeighbors.size());
				//	} while(!unvisitedNeighbors.test(distribution));
				//}
			}
			std::cout<<'\n';
		}

	}
}
