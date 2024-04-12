/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:26:45 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/12 11:00:09 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void) rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void) rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

e_literals determine_infinite_type(std::string input, double val)
{
	if (input == "-inff" || input == "+inff" || input == "inff")
	{
		std::cout << "char		: impossible" << std::endl
				  << "int		: impossible" << std::endl
				  << "float		: " << (input[0] == 43 ? "inff" : input) << std::endl
				  << "double		: " << val << std::endl;
		return (FLOAT);
	}
	if (input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "char		: impossible" << std::endl
				  << "int		: impossible" << std::endl
				  << "float		: " << (input[0] == 43 ? "inf" : input) << std::endl
				  << "double		: " << val << std::endl;
		return (DOUBLE);
	}
	return (NONE);
}

e_literals detect_finite_type(std::string input, double val)
{
	if (input == "-nanf" || input == "+nanf" || input == "nanf")
	{
		std::cout << "char		: impossible" << std::endl
				  << "int		: impossible" << std::endl
				  << "float		: " << (input[0] == 43 ? "nanf" : input) << std::endl
				  << "double		: " << val << std::endl;
		return (FLOAT);
	}
	if (input == "-nan" || input == "+nan" || input == "nan")
	{
		std::cout << "char		: impossible" << std::endl
				  << "int		: impossible" << std::endl
				  << "float		: " << val << "f" << std::endl
				  << "double		: " << val << std::endl;
		return (DOUBLE);
	}

	if (input.length() == 1)
	{
		char a;
		a = static_cast<char>(val);
		int i;
		i = static_cast<int>(val);
		std::cout << "char		: " << a << std::endl
				  << "int		: " << i << std::endl
				  << "float		: " << static_cast<float>(i) << std::endl
				  << "double		: " << static_cast<double>(i) << std::endl;
	}
	else
	{
		int i;
		i = static_cast<int>(val);
		(void) i;
	}
	return (NONE);
}

e_literals detect_type(std::string input, double val)
{
	if (std::isinf(val))
		return (determine_infinite_type(input, val));
	return (detect_finite_type(input, val));
}

/*
 * detect the type of the literal passed as parameter
 * str -> actual type
 * explicit conversion to int, float, double
 * display the results
 *
 * display err_msg accordingly for nonsensical conversions & overflows
 * handle numeric limits & special values
 *
 * char
 * ┕ only printable chars as input
 * ┕ if non-displayable after conversion, print a msg
 *
 * int
 * ┕
 *
 * floating point values or literal values default type if `double`
 * `float` if suffix `f` is present
 *
 * A valid floating point number for strtod using the "C" locale is formed by
 * ┕ an optional sign character (+ or -)
 * ┕ followed by a sequence of digits
 * ┕ optionally containing a decimal-point character (.)
 * ┕ optionally followed by an exponent part (an e or E character followed by an optional sign and a sequence of digits).
 *
 * float
 * ┕ handle pseudoliterals: -inff, +inff
 *
 * double
 * ┕ handle pseudoliterals: -inf, +inf, nan
 */
void ScalarConverter::convert(std::string input)
{
	const char *c_input = input.c_str();
	char *endptr;
	double res;

	res = strtod(c_input, &endptr);

	if (input == endptr)
	{
		if (input.length() == 1 && std::isprint(input[0]))
		{
			char a;
			a = static_cast<char>(input[0]);
			int i;
			i = static_cast<int>(input[0]);
			std::cout << "char		: " << a << std::endl
					  << "int		: " << i << std::endl
					  << "float		: " << static_cast<float>(i) << std::endl
					  << "double		: " << static_cast<double>(i) << std::endl;
		}
		else
			ERR_MSG_ONE(endptr);
	}
	else
		detect_type(input, res);
}
