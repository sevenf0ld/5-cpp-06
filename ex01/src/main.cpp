/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:53:14 by maiman-m          #+#    #+#             */
/*   Updated: 2024/08/12 19:47:37 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

// reference parameters are initialized with the actual arguments when the function is called.
// (source: https://www.ibm.com/docs/en/zos/2.4.0?topic=calls-pass-by-reference-c-only)
/*
void compare_struct(Data &ref, Data &new_ptr)
{
	std::cout << AC_YELLOW << &ref << "\t<obj>" << AC_NORMAL << std::endl
			  << "continent: " << ref.continent << std::endl
			  << "region: " << ref.region << std::endl
			  << "country: " << ref.country << std::endl;

	std::cout << AC_CYAN << &new_ptr << "\t<*ret>" << AC_NORMAL << std::endl
			  << "continent: " << new_ptr.continent << std::endl
			  << "region: " << new_ptr.region << std::endl
			  << "country: " << new_ptr.country << std::endl;
}
*/

void compare_struct(Data *ref, Data *new_ptr)
{
	std::cout << AC_YELLOW << ref << "\t`*obj`" << AC_NORMAL << std::endl
			  << "continent: " << ref->continent << std::endl
			  << "region: " << ref->region << std::endl
			  << "country: " << ref->country << std::endl;

	std::cout << AC_CYAN << new_ptr << "\t`*ret`" << AC_NORMAL << std::endl
			  << "continent: " << new_ptr->continent << std::endl
			  << "region: " << new_ptr->region << std::endl
			  << "country: " << new_ptr->country << std::endl;
}

int main(void)
{
	Data *obj = new Data;

	obj->continent = "Asia";
	obj->region = "SEA";
	obj->country = "Malaysia";

	// Use serialize() on the address of the Data object and pass its return value to deserialize(). Then, ensure the return value of deserialize() compares equal to the original pointer.
	Data *ret = Serializer::deserialize(Serializer::serialize(obj));
	compare_struct(obj, ret);
	std::cout << std::endl;

	std::cout << AC_BOLD << "Modifying data members of `Data *ret`..." << AC_NORMAL << std::endl
			  << std::endl;

	ret->continent = "Australia";
	ret->region = "Oceania";
	ret->country = "Australia";
	compare_struct(obj, ret);
	std::cout << std::endl;

	std::cout << AC_BOLD << "Modifications to `Data *ret` reflected in `Data *obj`, an indication that the retval of `deserialize()` does compare equal to the original pointer passed to it." << AC_NORMAL << std::endl
			  << std::endl;

	delete obj;

	// Serializer test;
}
