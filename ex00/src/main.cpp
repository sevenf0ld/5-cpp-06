/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:43:21 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:20 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Except for char parameters, only the decimal notation will be used
// Scientific notation is a way of expressing numbers that are too large or too small to be conveniently written in decimal form
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << AC_RED << "Usage: ./convert [input]" << AC_NORMAL << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	// ScalarConverter test;
}
