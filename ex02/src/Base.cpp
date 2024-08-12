/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:33:23 by maiman-m          #+#    #+#             */
/*   Updated: 2024/08/12 19:52:44 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

Base::~Base()
{
	FORMAT_COPY_CONTROL("Base dtor called.");
}

// indirection through a ref or ptr of base type to refer to derived type is allowed
// implicit upcasts are allowed whereas implicit downcasts are prohibited
// explicit downcasts can be achieved with `static_cast` only if the underlying object is of the derived type
// downcasts should not be through virtual inheritance

// dynamic_cast is exclusively used for handling polymorphism. You can cast a pointer or reference to any polymorphic type to any other class type (a polymorphic type has at least one virtual function, declared or inherited). You can use it for more than just casting downwards – you can cast sideways or even up another chain. The dynamic_cast will seek out the desired object and return it if possible. If it can't, it will return nullptr in the case of a pointer, or throw std::bad_cast in the case of a reference.
// dynamic_cast has some limitations, though. It doesn't work if there are multiple objects of the same type in the inheritance hierarchy (the so-called 'dreaded diamond') and you aren't using virtual inheritance. It also can only go through public inheritance - it will always fail to travel through protected or private inheritance. This is rarely an issue, however, as such forms of inheritance are rare.
// (source: https://stackoverflow.com/a/332086)

// randomly instantiate 'A', 'B' or 'C'
Base *generate(void)
{
	int num;
	Base *ret;

	srand(time(NULL));
	num = rand() % 3;
	if (num == 1)
	{
		ret = new (std::nothrow) A();
		if (ret != NULL)
			return (ret);
		NEW_ERR('A');
	}
	else if (num == 2)
	{
		ret = new (std::nothrow) B();
		if (ret != NULL)
			return (ret);
		NEW_ERR('B');
	}
	else
	{
		try
		{
			ret = new C();
			return (ret);
		}
		catch (const std::bad_alloc &e)
		{
			std::cout << e.what() << "\t";
			NEW_ERR('C');
		}
	}
	return (NULL);
}

// dynamic casts will succeed if the reference or pointer is the derived type it is casted to

// prints the actual type of 'p'
// return nullptr in the case of a pointer
void identify(Base *p)
{
	IDENTIFICATION("POINTER IDENTIFICATION");

	char type;

	if (dynamic_cast<A *>(p) != NULL)
		type = 'A';
	else if (dynamic_cast<B *>(p) != NULL)
		type = 'B';
	else if (dynamic_cast<C *>(p) != NULL)
		type = 'C';
	else
		type = 'X';
	if (type != 'X')
		std::cout << "base-class p points to derived-class " << type << std::endl
				  << std::endl;
	else
		std::cout << "base-class p is pointing to neither class A, B or C" << std::endl
				  << std::endl;
}

// prints the actual type of 'p'
// throw std::bad_cast in the case of a reference
// class bad_cast : public std::exception;
void identify(Base &p)
{
	IDENTIFICATION("REFERENCE IDENTIFICATION");

	char type = 'X';

	try
	{
		A &ret_a = dynamic_cast<A &>(p);
		(void)ret_a;
		type = 'A';
	}
	catch (std::exception &e)
	{
		std::cerr << AC_RED << "Not A. Maybe B?" << AC_NORMAL << std::endl;
		try
		{
			B &ret_b = dynamic_cast<B &>(p);
			(void)ret_b;
			type = 'B';
		}
		catch (std::exception &er)
		{
			std::cerr << AC_RED << "Not B. Perhaps C." << AC_NORMAL << std::endl;
			try
			{
				C &ret_c = dynamic_cast<C &>(p);
				(void)ret_c;
				type = 'C';
			}
			catch (std::exception &err)
			{
				std::cerr << AC_RED << "Not C. That's the end." << AC_NORMAL << std::endl;
			}
		}
	}
	if (type != 'X')
		std::cout << "base-class p points to derived-class " << type << std::endl
				  << std::endl;
	else
		std::cout << "base-class p is pointing to neither class A, B or C" << std::endl
				  << std::endl;
}
