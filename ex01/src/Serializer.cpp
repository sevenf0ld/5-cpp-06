/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:14:12 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/17 11:09:31 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &rhs)
{
	(void)rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer()
{
}

// 	Integer type capable of holding a value converted from a void pointer and then be converted back to that type with a value that compares equal to the original pointer.

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
