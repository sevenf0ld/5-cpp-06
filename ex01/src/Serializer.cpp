/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:14:12 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/16 16:18:09 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &rhs)
{
	(void) rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void) rhs;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr Serializer::serialize(Data *ptr)
{
}

Data *Serializer::deserialize(uintptr_t raw)
{
}
