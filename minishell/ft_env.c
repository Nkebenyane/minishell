/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 08:43:53 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/13 12:34:11 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	char **environ;

int prefix(char *cp, char *dp)
{
	while (*cp && *dp && *cp == *dp)
		cp++, dp++;
	if (*cp == 0)
		return (*dp == '=');
	return (0);
}

int ft_env(int argc, char **argv)
{
	register char **ep;
	int found = 0;

	argc--, argv++;
	if (environ)
	{
		ep = environ;
		while (*ep)
		{
			if (argc == 0 || prefix(argv[0], *ep))
			{
				register char *cp = *ep;

				found++;
				if (argc)
				{
					while (*cp && *cp != '=')
						cp++;
					if (*cp == '=')
						cp++;
				}
				printf("%s\n", cp);
			}
			ep++;
		}
	}
	exit (!found);
}
