/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_two.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:25:35 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/26 21:41:53 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZERO_TWO_H
#define ZERO_TWO_H

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

#define IDENTIFICATION(str) std::cout << AC_BOLD << AC_ITALIC << str << AC_NORMAL << std::endl
#define NEW_ERR(x) std::cerr << AC_RED << "Failed to instantiate " << x << "." << AC_NORMAL << std::endl
#define FORMAT_COPY_CONTROL(str) std::cout << AC_YELLOW << str << AC_NORMAL << std::endl

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#endif
