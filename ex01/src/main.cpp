/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:53:14 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/17 11:23:40 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

void compare_struct(Data &ref, Data &new_ptr)
{
	std::cout << AC_YELLOW << &ref << AC_NORMAL << std::endl
			  << "continent: " << ref.continent << std::endl
			  << "region: " << ref.region << std::endl
			  << "country: " << ref.country << std::endl;

	std::cout << AC_CYAN << &new_ptr << AC_NORMAL << std::endl
			  << "continent: " << ref.continent << std::endl
			  << "region: " << ref.region << std::endl
			  << "country: " << ref.country << std::endl;
}

int main(void)
{
	Data obj;
	Data *ret;

	obj.continent = "Asia";
	obj.region = "SEA";
	obj.country = "Malaysia";
	// Use serialize() on the address of the Data object and pass its return value to deserialize(). Then, ensure the return value of deserialize() compares equal to the original pointer.
	ret = Serializer::deserialize(Serializer::serialize(&obj));
	compare_struct(obj, *ret);
	std::cout << std::endl;

	ret->continent = "Australia";
	ret->region = "Oceania";
	ret->country = "Australia";
	compare_struct(obj, *ret);
	std::cout << std::endl;

	// Serializer test;
}
