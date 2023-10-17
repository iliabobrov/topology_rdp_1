#pragma once
#include <vector>
#include <span>

//a data structure reflecting some properties of a disk with ribbons
namespace ilia {
	class Disk {
	public:
		Disk(std::span<const size_t> array) : hieroglyph_(array.begin(), array.end()), strand_count_(array.size() / 2) {}

		//function that calculates the number of circles
		size_t CountEdgeCircle() const;
	private:
		std::vector<size_t> hieroglyph_;
		size_t strand_count_;
	};
}