/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:39:16 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/27 11:03:17 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c1)
{
	if (c1 >= 65 && c1 <= 90)
		return (c1 + 32);
	return (c1);
}
