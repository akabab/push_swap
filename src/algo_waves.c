#include "push_swap.h"

int			compt_waves(t_dlist *stack)
{
	t_dlist_node 	*cursor;
	int				i;

	cursor = stack->first;
	i = 0;
	while (cursor->next)
	{
		if (CURR_VAL(cursor) > NEXT_VAL(cursor))
			i++;
		cursor = cursor->next;
	}
	return (i);
}

int			compt_waves_reverse(t_dlist *stack)
{
	t_dlist_node 	*cursor;
	int				i;

	i = 0;
	if (!(cursor = stack->first))
		return (i);
	while (cursor->next)
	{
		if (CURR_VAL(cursor) < NEXT_VAL(cursor))
			i++;
		cursor = cursor->next;
	}
	return (i);
}

void		waves_sort(t_op ops[OPS_LEN], t_ps *ps)
{
	t_dlist_node	*node_a;
	t_dlist_node	*node_b;

	int				min;
	int				i;
	int				waves_a;
	int				waves_b;

	i = 0;
	min = find_min(ps->stack_a);
	waves_b = 0;
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
	{
		while (i != 0)
		{
			up(ops, ps, min);
			i++;
			waves_a = compt_waves(ps->stack_a);
			ft_printf("%d waves,  %d ps->total_ops\n", waves_a, ps->total_ops);
		}
		while (waves_a > waves_b)
		{
			OP(PB);
			waves_a = compt_waves(ps->stack_a);
			waves_b = compt_waves_reverse(ps->stack_b);
		}

		node_b = FIRST(ps->stack_b);
		node_a = LAST(ps->stack_a);
		while (node_b)
		{
			if (CURR_VAL(node_b) > CURR_VAL(node_a))
				OP(PA);
			else if (CURR_VAL(node_a) < PREV_VAL(node_a))
			{
				OP(RRA);
				OP(PA);
			}
			else
				OP(RRA);
			node_a = LAST(ps->stack_a);
			node_b = FIRST(ps->stack_b);
		}
		waves_a = compt_waves(ps->stack_a);
		waves_b = compt_waves_reverse(ps->stack_b);
		ft_printf("%d waves_a,  %d waves_b\n", waves_a, waves_b);
	}
}
