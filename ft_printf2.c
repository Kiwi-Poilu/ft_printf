void	ft_init_flags(t_flags *flags)
{
	flags->depht = 0;
	flags->start = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
}

int		ft_parsing(const char *str, va_list args, int *i)
{
	int ret;
	char c;
	t_flags flags;
	ft_init_flags(&flags);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		out;
	va_list	args;

	i = 0;
	out = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			out += ft_parsing(str, args, &i);
		else
			out += ft_putchar(str[i++]);
	}
	va_end(args)
	return (i);

}
