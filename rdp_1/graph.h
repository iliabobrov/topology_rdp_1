#pragma once
#include <vector>

namespace ilia {
	//standard graph implemented using an adjacency list
	class Graph {
	public:
		Graph(size_t vertex_count = 0) : adjacency_list_(vertex_count), size_(vertex_count) {}

		void AddEdge(size_t begin, size_t end);
		void Resize(size_t new_vertex_count);

		std::vector<size_t> GetNeighbours(size_t vertex) const;
		size_t Size() const { return size_; }
	private:
		std::vector<std::vector<size_t> > adjacency_list_;
		size_t size_;
	};

	size_t ConnectedComponentsCount(const Graph& graph);

	enum class DFSColor { White, Gray, Black };

	template<typename RootVisit, typename EdgeVisit, typename VertexLeave>
	//DFS graph traversal structure
	//can take lambda functions as input to process vertices when traversing
	class DFS {
	public:
		DFS() = delete;
		DFS(const DFS&) = delete;
		DFS(DFS&&) = delete;

		DFS(const Graph& graph, const RootVisit& root_visit, const EdgeVisit& edge_visit, const VertexLeave& vertex_leave) {
			std::vector<DFSColor> colors(graph.Size(), DFSColor::White);
			std::vector<size_t> time_in(graph.Size(), 0);
			size_t time = 0;
			for (size_t vertex = 0; vertex < graph.Size(); ++vertex) {
				if (colors[vertex] == DFSColor::White) {
					root_visit(vertex, time);
					DFSVisit(graph, vertex, colors, time_in, time, edge_visit, vertex_leave);
				}
			}
		}
	private:
		void DFSVisit(const Graph& graph, size_t vertex, std::vector<DFSColor>&colors, std::vector<size_t>&time_in, size_t& time, const EdgeVisit& edge_visit, const VertexLeave& vertex_leave) {
			colors[vertex] = DFSColor::Gray;
			time_in[vertex] = time++;

			for (size_t neighbour : graph.GetNeighbours(vertex)) {
				edge_visit(vertex, neighbour, time_in[vertex], time, time_in[neighbour], colors[neighbour]);
				if (colors[neighbour] == DFSColor::White) {
					DFSVisit(graph, neighbour, colors, time_in, time, edge_visit, vertex_leave);
				}
			}

			colors[vertex] = DFSColor::Black;
			vertex_leave(vertex, time_in[vertex], time);
		}
	};
}