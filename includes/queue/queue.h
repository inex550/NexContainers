#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <vector/vector.h>

namespace nex {
	template <typename Ty, typename CTy = nex::vector<Ty>>
	class queue {
	public:
		using container_type	= CTy;
		using value_type		= typename container_type::value_type;
		using reference			= typename container_type::reference;
		using const_reference	= typename container_type::const_reference;
		using size_type			= typename container_type::size_type;

	public:
		queue() = default;
		queue(std::initializer_list<value_type> const& items) : container(items) {}

		queue(const queue& other) = default;
		queue(queue&& other) noexcept = default;
		queue& operator=(const queue& other) = default;
		queue& operator=(queue&& other) noexcept = default;

		const_reference front() const { return container.front(); }
		const_reference back() const { return container.back(); }

		bool empty() const { return container.empty(); }
		size_type size() const { return container.size(); }

		void push(const_reference value) { container.push_back(value); }

		void pop() { container.erase(container.begin()); }

		void swap(queue& other) { container.swap(other.container); }

		template<typename... Args>
		void emplace(Args&&... args) { container.emplace_back(std::forward<Args>(args)...); }

		template<typename... Args> 
		void emplace_back(const_reference value) { container.emplace_back(value); }

	private:
		container_type container;
	};
}  // namespace nex

#endif  // __QUEUE_H__
