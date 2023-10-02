#pragma once
#include <cell.h>
#include <vector>

namespace maze {
	class generator {
		public:
			generator();
			generator(unsigned int length,unsigned int width,unsigned int height);
			void generate();
		private:
			std::vector<std::vector<std::vector<cell>>> maze;
	};
}
