#ifndef __STACK_H__
#define __STACK_H__

#include <vector/vector.h>

namespace nex {
	template <typename T, typename CTy = nex::vector<T>>
	class stack {
	public:
		using container_type	= CTy;
		using value_type		= typename Container::value_type;
		using reference			= typename Container::reference;
		using const_reference	= typename Container::const_reference;
		using size_type			= typename Container::size_type;

	public:
		stack() = default;
		stack(std::initializer_list<value_type> const &items) : container(items) {}

		stack(const stack &other) = default;
		stack(stack &&other) noexcept = default;
		stack &operator=(const stack &other) = default;
		stack &operator=(stack &&other) noexcept = default;

		const_reference top() const { return container.back(); }

		bool empty() const { return container.empty(); }
		size_type size() const { return container.size(); }

		void push(const_reference value) { container.push_back(value); }

		void pop() { container.pop_back(); }

		void swap(stack &other) { container.swap(other.container); }

		template<typename... Args>
		void emplace(Args&&... args) { container.emplace_back(args...); }

		template<typename... Args>
		void emplace_back(Args&&... args) { container.push_back(args...); }

		template<typename... Args>
		void emplace_front(Args&&... args) { container.emplace_back(args...); }

	private:
		container_type container;
	};
}  // namespace nex

#endif  // __STACK_H__
