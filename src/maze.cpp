#include <vector>
#include <stack>
#include <iostream>
#include <random>
#include <bitset>

int main() {

	std::vector<std::vector<std::bitset<4>>> maze(10,std::vector<std::bitset<4>>(10,0));		// bitset for each cardinal direction: 0001=N,0010=E,0100=S,1000=W,etc

	std::random_device r;
	std::mt19937 rng(r());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0,4);

	for(auto columns : maze) {
		for(auto cell : columns) {
			for(unsigned short bit=0;bit<=cell.size();++bit) {
				cell |= 1<<dist(rng);		// shift a 1 into any of the 4 bits based on random chance
			}
			std::cout<<cell<<' ';
		}
		std::cout<<'\n';
	}

	return 0;
}
