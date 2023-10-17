#include "disk.h"
#include "graph.h"

namespace ilia {
	//function that calculates the number of circles
	size_t Disk::CountEdgeCircle() const {
		std::vector<size_t> symbol_connection(strand_count_, -1);
		//creating a graph with 4n vertices
		Graph graph(strand_count_ * 4);

		//constructing a graph from a disk
		for (size_t i = 0; i < strand_count_ * 2; ++i) {
			if (symbol_connection[hieroglyph_[i]] == -1) {
				symbol_connection[hieroglyph_[i]] = i;
			} else {
				graph.AddEdge(2 * i, 2 * symbol_connection[hieroglyph_[i]] + 1);
				graph.AddEdge(2 * i + 1, 2 * symbol_connection[hieroglyph_[i]]);
			}
			graph.AddEdge(2 * i + 1, 2 * ((i + 1) % (strand_count_ * 2)));
		}
		return ConnectedComponentsCount(graph);
	}
}