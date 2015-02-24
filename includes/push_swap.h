#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> // !!!

/*
**		COLOR
*/
# define RED		"31"
# define GREEN		"32"
# define YELLOW		"33"
# define BLUE		"34"
# define PINK		"35"
# define GRBL		"36"
# define GREY		"37"
# define NO			"0"
# define C(X)		"\033["X"m"
# define CC(X)		"\033[3"X"m"
# define CB(X)		"\x1B[48;1;"X"m"
# define CBNO		"\x1B[0m"

enum				opts
{
	OPT_VERBOSE = 1 << 0,
	OPT_COLOR = 1 << 1,
	OPT_INTERACTIVE = 1 << 2,
	OPT_TIME = 1 << 3
};

# define MAX_OPS	1000000
# define OP_SLEEP	1

# define CURR_VAL(X)	(*(int *)X->value)
# define NEXT_VAL(X)	(*(int *)X->next->value)
# define PREV_VAL(X)	(*(int *)X->prev->value)

typedef	struct		s_ps
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	char		options;
	int			total_ops;
}					t_ps;

/*
**		ops
*/
typedef struct		s_op
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_op;

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OPS_LEN
};

void			sa(t_ps *ps);
void			sb(t_ps *ps);
void			ss(t_ps *ps);
void			pa(t_ps *ps);
void			pb(t_ps *ps);
void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);
void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);

/*
**		algos
*/
typedef struct		s_algo
{
	char		*name;
	void		(*f)(t_op ops[OPS_LEN], t_ps *ps);
}					t_algo;

enum
{
	BBS,
	FF,
	IM,
	ALGOS_LEN
};

void			bubble_sort(t_op ops[OPS_LEN], t_ps *ps);
void			fifty_fifty(t_op ops[OPS_LEN], t_ps *ps);
void			interactive_mode(t_op ops[OPS_LEN], t_ps *ps);

/*
**		resolve.c
*/
t_bool			is_sort(t_dlist *stack);
t_bool			is_sort2(t_dlist *stack);
int				find_min(t_dlist_node *node);
void			resolve(t_op ops[OPS_LEN], t_ps *ps, t_algo *algo);
void			call_op(int op, t_op ops[OPS_LEN], t_ps *ps);

/*
**		parser.c
*/
void			parse(t_ps *ps, int ac, char *av[]);

/*
**		print.c
*/
void			print_stack(t_dlist *dlist);
void			display_stacks(t_ps *ps);

#endif
