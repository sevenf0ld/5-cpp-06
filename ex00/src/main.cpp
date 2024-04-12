/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:43:21 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/12 10:54:48 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Except for char parameters, only the decimal notation will be used
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << AC_RED << "Usage: ./convert [input]" << AC_NORMAL << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
