#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

#include <range/v3/algorithm.hpp>
#include <range/v3/numeric.hpp>
#include <range/v3/view.hpp>

template<typename V>
struct prime_generator
	: ranges::view_facade<prime_generator<V>, ranges::infinite>
{
	static_assert(std::is_integral_v<V>, "prime_generator must be templated on an integral type.");
private:
	friend ranges::range_access;
	using p_elt = std::pair<V, V>;
	// store the mesh of the sieve
	std::vector<p_elt> sieve_;
	// apply the sieve
	bool sieve()
	{
		// Decrement each counter and sum the zeroes. Reset the counter.
		// Any zero at all means current element is a factor and hence current prime_ not actually prime
		// So return == 0 to indicate prime.
		//
		return std::transform_reduce(std::begin(sieve_), std::end(sieve_),
			V(0),   // initial value
			std::plus<V>(),  // reduction
			[](auto& elt) // apply to each element
		{
			--elt.second;
			if (elt.second == 0)
			{
				elt.second = elt.first;
				return V(1);
			}
			else
				return V(0);
		}) == V(0);
	}
	V prime_;

	V read() const
	{
		return prime_;
	}
	void next()
	{
		++prime_;
		while (!sieve())
			++prime_;
		sieve_.emplace_back(prime_, prime_);
	}
	constexpr bool equal(ranges::default_sentinel_t) const
	{
		return false;
	}
public:
	prime_generator()
	{
		prime_ = V(2);
		sieve_.emplace_back(prime_, prime_);
	}
};

int main()
{
	std::cout << "First 100 primes are - \n";
	ranges::for_each(prime_generator<int>() | ranges::views::take(100), [](auto p) { std::cout << p << ", "; });
	std::cout << '\n';

	std::cout << "Sum of primes less than 1000 = " <<
		ranges::accumulate(prime_generator<int>() | ranges::views::take_while([](auto p) { return p < 1000; }), 0) << '\n';
}