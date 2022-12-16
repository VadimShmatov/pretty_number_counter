#pragma once
#include <cassert>
#include <ranges>
#include <array>
#include <bit>

template<size_t num_system_base, size_t number_size, size_t init_region_size>
class PrettyNumberCounter
{
private:
	static constexpr const size_t region_size = (2 * init_region_size > number_size) ? (number_size - init_region_size) : (init_region_size);
	static constexpr const size_t unused_digits = number_size - 2 * region_size;
	static constexpr const size_t max_sum = (num_system_base - 1) * region_size + 1;
	std::array<uint32_t, max_sum * region_size> sums{};

	void calculate_sums()
	{
		for (size_t sum : std::views::iota(0u, num_system_base)) {
			sums[sum] = 1;
		}
		for (size_t step : std::views::iota(1u, region_size)) {
			for (size_t sum : std::views::iota(0u, max_sum)) {
				size_t subsum = 0;
				for (size_t digit : std::views::iota(0u, std::min(sum + 1, num_system_base))) {
					subsum += sums[max_sum * (step - 1) + sum - digit];
				}
				sums[max_sum * step + sum] = subsum;
			}
		}
	}

	uint64_t calculate_solution()
	{
		uint64_t result = 0;
		for (size_t sum : std::views::iota(0u, max_sum)) {
			result += sums[max_sum * (region_size - 1) + sum] * sums[max_sum * (region_size - 1) + sum];
		}
		for (size_t unused_digit : std::views::iota(0u, unused_digits)) {
			result *= num_system_base;
		}
		return result;
	}

public:
	PrettyNumberCounter()
	{
		// Make sure solution fits into 64-bit integer
		static_assert(number_size * std::bit_width(num_system_base) < 64);
	}

	uint64_t count()
	{
		calculate_sums();
		return calculate_solution();
	}
};