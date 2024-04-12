/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:26:45 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/12 16:41:42 by maiman-m         ###   ########.fr       */
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

void handle_numeric_limits(std::string input, double val)
{
	// float_val is to not print the leading positive sign
	std::string float_val(input[0] == 43 ? "inff" : input);

	std::cout << "char		: impossible" << std::endl
			   << "int		: impossible" << std::endl;

	if (input == "-inf" || input == "+inf" || input == "inf")
		std::cout << "float		: " << (float_val == input ? input + "f" : float_val) << std::endl;
	else
		std::cout << "float		: " << float_val << std::endl;

	std::cout << "double		: " << val << std::endl;
}

e_literals handle_special_values(std::string input, double val)
{
	std::cout << "char		: impossible" << std::endl
			  << "int		: impossible" << std::endl;
	if (input[input.length() - 1] == 'f')
		std::cout << "float		: " << (input[0] == 43 ? "nanf" : input) << std::endl;
	else
		std::cout << "float		: " << val << "f" << std::endl;
	std::cout << "double		: " << val << std::endl;
	return (NN);
}

e_literals handle_finite(std::string input, double val)
{
	if (input.length() == 1 && std::isprint(input[0]))
	{
		if (!std::isdigit(input[0]))
			return (CHAR);
		else
			return (INT);
	}
	if (input[input.length() - 1] != 'f')
		return (FLOAT);
	else
		return (DOUBLE);
	(void) val;
	return (NONE);
}

e_literals determine_input(std::string input, double val)
{
	if (std::isnan(val))
		return (handle_special_values(input, val));
	else if (std::isfinite(val))
		return (handle_finite(input, val));
	return (NONE);
}

void detect_type(std::string input, double val)
{
	if (std::isinf(val))
		handle_numeric_limits(input, val);
	determine_input(input, val);
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
		// check for invalid floating point number (leading non-digits)
		if (input.length() != 1)
			INVALID_CONVERSION(endptr);
		// allow single characters
		else
			detect_type(input, res);
	}
	else
	{
		// check for invalid floating point number (trailing non-digits)
		// c++11 allows input.back()
		if (endptr != NULL && std::string(endptr).length() != 0 && input[input.length() - 1] != 'f')
			INVALID_CONVERSION(endptr);
		// allow float-representation
		else
			detect_type(input, res);
	}
}
