/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:22:33 by ycribier          #+#    #+#             */
/*   Updated: 2015/03/02 17:51:59 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_env(t_env *e)
{
	free(e->img);
	free(e->keys);
	free(e->palette);
	free(e);
}

t_env		*mlx_env_instance(t_env *env)
{
	static t_env	*e = NULL;

	if (!e)
		e = env;
	return (e);
}

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		exit(-1);
	if ((e->mlx = mlx_init()) == NULL)
	{
		perror("[MLX]: Connexion to server X failed.");
		exit(-1);
	}
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "--PUSH_SWAP--")))
	{
		perror("[MLX]: New window creation failed.");
		exit(-1);
	}
	if (!(e->img = create_new_image(e, W_WIDTH, W_HEIGHT)))
		exit(-1);
	if (!(e->keys = init_keys()))
		exit(-1);
	e->palette = gen_gradient_palette(hex_to_rgb(STACK_COL1),
		hex_to_rgb(STACK_COL2), PALETTE_SIZE);
	return (mlx_env_instance(e));
}
