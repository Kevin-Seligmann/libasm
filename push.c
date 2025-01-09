typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (0);
	lst->data = data;
	lst->next = 0;
	return (lst);	
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (!begin_list)
		return ;
	new_node = ft_create_elem(data);
	if (!new_node)
		return ;
	new_node->next = (*begin_list)->next;
	*begin_list = new_node;
}
