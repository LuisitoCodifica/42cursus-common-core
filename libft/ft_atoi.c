/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:17:27 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/13 18:18:19 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

// n = n * 10 + (*nptr - '0');

int	ft_atoi(const char *nptr)
{
	// return ((int) *nptr);
	return 0;
}

void test(const char *input, int res, int exp) {
	if (res == exp) {
		printf("\x1b[32mOK\n");
	} else {
		printf("\x1b[31mKO -> input: ", input);
		while (*input) {
			if (*input == ' ')
				printf("\\s");
			else {
				if (isprint(*input))
					printf("%c", *input);
				else
					printf("\\0%02o", *input);
			}
			input++;
		}
		printf("\n\\___ result: %d, expected: %d\n", res, exp);
	}
}

int main() {
{
	test(" \t\v\n\r\f123", ft_atoi(" \t\v\n\r\f123"), 123);
	test("0", ft_atoi("0"), 0);
	test("-1000043", ft_atoi("-1000043"), -1000043);
	test("+0000000000000000000000000000000000000000000000000000123", ft_atoi("+0000000000000000000000000000000000000000000000000000123"), 123);
	test("    123", ft_atoi("    123"), 123);
	test("--123", ft_atoi("--123"), 0);
	test("-+123", ft_atoi("-+123"), 0);
	test("+-123", ft_atoi("+-123"), 0);
	test("++123", ft_atoi("++123"), 0);
	test("- 123", ft_atoi("- 123"), 0);
	test("+ 123", ft_atoi("+ 123"), 0);
	test("+\n123", ft_atoi("+\n123"), 0);
	test("1209", ft_atoi("1209"), 1209);
	test("12/3", ft_atoi("12/3"), 12);
	test("12;3", ft_atoi("12;3"), 12);
	test("2147483647", ft_atoi("2147483647"), 2147483647);
	test("-2147483648", ft_atoi("-2147483648"), -2147483648);
	test("\001 2", ft_atoi("\001 2"), 0);
	test("\002 3", ft_atoi("\002 3"), 0);
	test("\003 4", ft_atoi("\003 4"), 0);
	test("\004 5", ft_atoi("\004 5"), 0);
	test("\005 6", ft_atoi("\005 6"), 0);
	test("\006 7", ft_atoi("\006 7"), 0);
	test("\007 8", ft_atoi("\007 8"), 0);
	test("\010 9", ft_atoi("\010 9"), 0);
	test("\t 10", ft_atoi("\t 10"), 10);
	test("\n 11", ft_atoi("\n 11"), 11);
	test("\v 12", ft_atoi("\v 12"), 12);
	test("\f 13", ft_atoi("\f 13"), 13);
	test("\r 14", ft_atoi("\r 14"), 14);
	test("\016 15", ft_atoi("\016 15"), 0);
	test("\017 16", ft_atoi("\017 16"), 0);
	test("\020 17", ft_atoi("\020 17"), 0);
	test("\021 18", ft_atoi("\021 18"), 0);
	test("\022 19", ft_atoi("\022 19"), 0);
	test("\023 20", ft_atoi("\023 20"), 0);
	test("\024 21", ft_atoi("\024 21"), 0);
	test("\025 22", ft_atoi("\025 22"), 0);
	test("\026 23", ft_atoi("\026 23"), 0);
	test("\027 24", ft_atoi("\027 24"), 0);
	test("\030 25", ft_atoi("\030 25"), 0);
	test("\031 26", ft_atoi("\031 26"), 0);
	test("\032 27", ft_atoi("\032 27"), 0);
	test("\033 28", ft_atoi("\033 28"), 0);
	test("\034 29", ft_atoi("\034 29"), 0);
	test("\035 30", ft_atoi("\035 30"), 0);
	test("\036 31", ft_atoi("\036 31"), 0);
	test("\037 32", ft_atoi("\037 32"), 0);
}
	return 0;
}
