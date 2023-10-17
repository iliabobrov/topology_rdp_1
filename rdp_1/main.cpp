#include <iostream>
#include "disk.h"
#include "graph.h"
#include <string>

bool IsExist(std::vector<size_t> v) {
	for (auto i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::sort(v.begin(), v.end());
	if (v.size()%2 != 0) {
		return false;
	}
	while (v.size() > 2) {
		if ((v[v.size() - 1] == v[v.size() - 2]) && (v[v.size() - 2] != v[v.size() - 3])) {
			v.pop_back();
			v.pop_back();
		} else {
			return false;
		}
	}
	std::cout << v.size() << std::endl;
	if (v[0] != v[1]) {
		return false;
	}
	return true;
}


//
int main() {
	std::cout << "enter 2n characters specifying the hyerogliph \n \\
	(use the first n letters of the English alphabet)" << std::endl;
	std::cout << "when finished, enter \'0\'" << std::endl;
	while (true) {
		std::string char_hieroglyph;
	
		//data input
		std::cin >> char_hieroglyph;
		if (char_hieroglyph == "0") {
			std::cout << "end" << std::endl;
			break;
		}

		//converting hieroglyph to integer type
		std::vector<size_t> hieroglyph;
		for (char letter : char_hieroglyph) {
			size_t vertex = static_cast<size_t>(letter - 'a');
			hieroglyph.push_back(vertex);
		}

		//creating a disk structure and calling the circle counting function
		//(the disk structure is described in the file disk.h)
		std::cout << "quantity : " << ilia::Disk(hieroglyph).CountEdgeCircle() << std::endl;
	}
	return 0;
}