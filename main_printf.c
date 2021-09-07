/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 09:52:54 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 10:00:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int main(void)
{
	int ori;
	int ft_;
	char *str;

	str = "coucou";
	ori = printf(str);
	ft_ = ft_printf(str);
	printf("\nori : %i, ft_ : %i\n", ori, ft_);

	str = "";
	ori = printf(str);
	ft_ = ft_printf(str);
	printf("\nori : %i, ft_ : %i\n", ori, ft_);

	str = "";
	ori = printf("|%s|\n", str);
	ft_ = ft_printf("|%s|\n", str);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	str = "coucou";
	ori = printf("|%s|\n", str);
	ft_ = ft_printf("|%s|\n", str);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	str = "coucou";
	ori = printf("|%s| |%s|\n", str, "toi");
	ft_ = ft_printf("|%s| |%s|\n", str, "toi");
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	ori = printf("|%p| |%p|\n", str, NULL);
	ft_ = ft_printf("|%p| |%p|\n", str, NULL);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	ori = printf("|%i| |%d| |%i|\n", 0, -42, +19);
	ft_ = ft_printf("|%i| |%d| |%i|\n", 0, -42, +19);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	ori = printf("|%x| |%X| |%x|\n", 0, -42, +19);
	ft_ = ft_printf("|%x| |%X| |%x|\n", 0, -42, +19);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

	ori = printf("|%u| |%u| |%u|\n", 0, 2147483647, +19);
	ft_ = ft_printf("|%u| |%u| |%u|\n", 0, 2147483647, +19);
	printf("ori : %i, ft_ : %i\n", ori, ft_);

}