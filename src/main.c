#include "push_swap.h"

static t_op		g_ops[OPS_LEN] =
{
	{"sa", &sa},
	{"sb", &sb},
	{"ss", &ss},
	{"pa", &pa},
	{"pb", &pb},
	{"ra", &ra},
	{"rb", &rb},
	{"rr", &rr},
	{"rra", &rra},
	{"rrb", &rrb},
	{"rrr", &rrr}
};

static t_algo	g_algos[ALGOS_LEN] =
{
	{"bbs", &bubble_sort},
	{"ff", &fifty_fifty},
	{"up", &up_down},
	{"im", &interactive_mode}
};

static void		free_all(t_ps *ps, t_env *e)
{
	if ((e = mlx_env_instance(NULL)))
		free_env(e);
	//delete stacks
	free(ps);
}

static t_ps		*init_ps(void)
{
	t_ps	*ps;

	if (!(ps = (t_ps *)ft_memalloc(sizeof(t_ps))))
		exit(-1);
	ps->stack_a = dlist_create();
	ps->stack_b = dlist_create();
	return (ps);
}

int				main(int ac, char *av[])
{
	t_ps	*ps;
	t_env	*e;

	if (ac < 2)
		error_msg_exit(USAGE);
	ps = init_ps();
	parse(ps, g_algos, ac, av);
	if (OPT(OPT_GRAPHIC))
		e = init_env();
	resolve(g_ops, ps, &g_algos[ps->algo]);
	free_all(ps, e);
	return (0);
}
