/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:26:45 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/26 17:08:26 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void)rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void handle_numeric_limits(std::string input, double val)
{
	// not print the leading positive sign
	std::string float_val(input[0] == 43 ? "inff" : input);

	std::cout << "char		: impossible" << std::endl
			  << "int		: impossible" << std::endl;

	if (input == "-inf" || input == "+inf" || input == "inf")
		std::cout << "float		: " << (float_val == input ? input + "f" : float_val) << std::endl;
	else
		std::cout << "float		: " << float_val << std::endl;

	std::cout << "double		: " << val << std::endl;
}

void handle_special_values(std::string input, double val)
{
	std::cout << "char		: impossible" << std::endl
			  << "int		: impossible" << std::endl;
	if (input[input.length() - 1] == 'f')
		std::cout << "float		: " << (input[0] == 43 ? "nanf" : input) << std::endl;
	else
		std::cout << "float		: " << val << "f" << std::endl;
	std::cout << "double		: " << val << std::endl;
}

e_literals handle_finite(std::string input)
{
	std::size_t found;

	found = input.find('.');
	if (input.length() == 1 && std::isprint(input[0]))
	{
		if (!std::isdigit(input[0]))
			return (CHAR);
		else
			return (INT);
	}
	if (input[input.length() - 1] == 'f')
		return (FLOAT);
	// returns size_t of npos (last element) in the string if not found
	else if (found == std::string::npos)
		return (INT);
	else
		return (DOUBLE);
	return (NONE);
}

void handle_char(std::string input)
{
	char a;

	a = input[0];
	std::cout << "char		: " << a << std::endl
			  << "int		: " << static_cast<int>(a) << std::endl
			  << "float		: " << static_cast<float>(a) << ".0f" << std::endl
			  << "double		: " << static_cast<double>(a) << ".0" << std::endl;
}

void handle_int(std::string input)
{
	int i;
	// -pedantic turns off the extension for long long which is not supported by c++98
	// long long j;
	int64_t j; // for portability
	char a;

	i = strtol(input.c_str(), NULL, 10);
	j = strtol(input.c_str(), NULL, 10);
	a = static_cast<char>(i);
	if (std::isprint(a))
		std::cout << "char		: " << a << std::endl;
	else
		NONDISPLAYABLE();
	if (j > INT_MAX || j < INT_MIN)
		OVERFLOW();
	else
		std::cout << "int		: " << i << std::endl;
	std::cout << "float		: " << static_cast<float>(i) << ".0f" << std::endl
			  << "double		: " << static_cast<double>(i) << ".0" << std::endl;
}

void handle_float(std::string input)
{
	float i;
	char a;
	std::size_t found;
	std::string suffix_f;
	std::string suffix_d;
	// if Boost was allowed, lexicial_cast is an alternative
	std::ostringstream i_oss;
	std::string f_input;

	i = strtof(input.c_str(), NULL);
	a = static_cast<char>(i);
	found = input.find('.');
	i_oss << i;
	// the getter/setter
	f_input = i_oss.str();
	if (std::isprint(a))
		std::cout << "char		: " << a << std::endl;
	else
		NONDISPLAYABLE();
	std::cout << "int		: " << static_cast<int>(i) << std::endl;
	if (found == std::string::npos)
	{
		std::cout << "float		: " << i << ".0f" << std::endl
				  << "double		: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{
		found = f_input.find('.');
		// if (input[input.length() - 2] == '0' && found != std::string::npos)
		//	suffix = "0f";
		if (input[input.length() - 2] == '0' && found == std::string::npos)
		{
			suffix_f = ".0f";
			suffix_d = ".0";
		}
		else
			suffix_f = "f";
		std::cout << "float		: " << i << suffix_f << std::endl
				  << "double		: " << static_cast<double>(i) << suffix_d << std::endl;
	}
}

void handle_double(std::string input)
{
	double i;
	char a;
	std::size_t found;
	std::string suffix_f;
	std::string suffix_d;
	std::ostringstream i_oss;
	std::string d_input;

	i = strtod(input.c_str(), NULL);
	a = static_cast<char>(i);
	found = input.find('.');
	i_oss << i;
	d_input = i_oss.str();
	if (std::isprint(a))
		std::cout << "char		: " << a << std::endl;
	else
		NONDISPLAYABLE();
	std::cout << "int		: " << static_cast<int>(i) << std::endl;
	if (found == std::string::npos)
	{
		std::cout << "float		: " << static_cast<float>(i) << ".0f" << std::endl
				  << "double		: " << i << ".0" << std::endl;
	}
	else
	{
		// check if the last character is '0'
		// use sstream to convert double back to string or check the arg
		// check the arg but this breaks 3.30
		// if (input[input.length() - 1] == '0')
		// suffix = ".0f";
		found = d_input.find('.');
		// if (input[input.length() - 1] == '0' && found != std::string::npos)
		//	suffix = "0f";
		if (input[input.length() - 1] == '0' && found == std::string::npos)
		{
			suffix_f = ".0f";
			suffix_d = ".0";
		}
		else
			suffix_f = "f";
		std::cout << "float		: " << static_cast<float>(i) << suffix_f << std::endl
				  << "double		: " << i << suffix_d << std::endl;
	}
}

void determine_input(std::string input, double val)
{
	if (std::isnan(val))
		handle_special_values(input, val);
	else if (std::isfinite(val))
	{
		switch (handle_finite(input))
		{
		case CHAR:
			handle_char(input);
			break;
		case INT:
			handle_int(input);
			break;
		case FLOAT:
			handle_float(input);
			break;
		case DOUBLE:
			handle_double(input);
			break;
		default:
			break;
		}
	}
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
 * ┕ handle pseudoliterals: -inff, +inff, nanf
 *
 * double
 * ┕ handle pseudoliterals: -inf, +inf, nan
 */
void ScalarConverter::convert(std::string input)
{
	size_t found;
	const char *c_input = input.c_str();
	char *endptr;
	double res;

	found = input.find('e');
	res = strtod(c_input, &endptr);

	// A pointer to the rest of the string after the last valid character is stored in the object pointed by endptr.
	if (input == endptr)
	{
		// check for leading non-digits
		if (input.length() != 1)
			INVALID_CONVERSION(endptr);
		// allow single characters
		else
			detect_type(input, res);
	}
	else
	{
		// check for trailing non-digits apart from f or before f
		// c++11 allows input.back()
		if (endptr != NULL && std::string(endptr).length() != 0 && input[input.length() - 1] != 'f')
			INVALID_CONVERSION(endptr);
		else if (endptr != NULL && std::string(endptr).length() != 0 && input[input.length() - 1] == 'f')
		{
			std::string tmp = input.substr(0, input.length() - 1);
			char check = tmp[tmp.length() - 1];
			if (!isdigit(check) && !std::isnan(res) && !std::isinf(res))
				INVALID_CONVERSION(endptr);
			else
				// allow float-representation
				detect_type(input, res);
		}
		else if (found != std::string::npos)
		{
			std::cout << input << std::endl;
			REJECT_INPUT();
		}
		// allow float-representation
		else
			detect_type(input, res);
	}
}
