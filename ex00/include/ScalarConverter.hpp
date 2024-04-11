/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:27:36 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/11 17:00:20 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"
#define AC_BOLD "\033[1m"
#define AC_ITALIC "\033[3m"

enum e_literals
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID = -1
};

#include <iostream>
#include <string>
#include <sstream>

// must not be instantiable
class ScalarConverter
{
public:
	// no need to instantiate a ScalarConverter object to access the static method's functionality as it has no `this` ptr
	// (source: https://www.learncpp.com/cpp-tutorial/static-member-functions/)
	static void convert(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
};

#endif
