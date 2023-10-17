#include "graph.h"

namespace ilia {
	void Graph::AddEdge(size_t begin, size_t end) {
		adjacency_list_[begin].push_back(end);
		adjacency_list_[end].push_back(begin);
	}

	void Graph::Resize(size_t new_vertex_count) {
		adjacency_list_.resize(new_vertex_count);
	}

	std::vector<size_t> Graph::GetNeighbours(size_t vertex) const {
		return adjacency_list_[vertex];
	}

	//counting the number of connected components by repeatedly calling the DFS algorithm
	size_t ConnectedComponentsCount(const Graph& graph) {
		size_t connected_components_count = 0;
		auto root_visit = [&connected_components_count](size_t vertex, size_t time) { ++connected_components_count; };
		auto edge_visit = [](size_t begin, size_t end, size_t begin_time, size_t end_time, size_t current_time, DFSColor color) {};
		auto vertex_leave = [](size_t vertex, size_t time_in, size_t time_out) {};
		DFS<decltype(root_visit), decltype(edge_visit), decltype(vertex_leave)>(graph, root_visit, edge_visit, vertex_leave);
		return connected_components_count;
	}
}