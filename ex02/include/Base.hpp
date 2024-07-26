/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:23 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/26 21:41:51 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

#ifndef BASE_HPP
#define BASE_HPP

// the type must be polymorphic to use dynamic_cast
class Base
{
public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
