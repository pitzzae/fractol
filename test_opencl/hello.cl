
typedef struct	s_complex
{
	double			real;
	double			imag;
}				t_complex;

void		ft_cplx_mul(__global t_complex* a)
{
	double			tmp[2];

	tmp[0] = a[3].real;
	tmp[1] = a[3].imag;
	a[3].real = tmp[0] * tmp[0] - tmp[1] * tmp[1];
	a[3].imag = tmp[0] * tmp[1] + tmp[1] * tmp[0];
}

t_complex	ft_cplx_pow(__global t_complex* a, int p)
{
	int				loop;

	loop = 0;
	a[3].real = a[1].real;
	a[3].imag = a[1].imag;
	if (p > 0)
	{
		while (loop < p)
		{
			ft_cplx_mul(a);
			loop++;
		}
	}
	return (a[3]);
} 

t_complex	test2(t_complex a)
{
	a.real = -0.772691322542185;
	a.imag = 0.124281466072787;
	return(a);
}


double		test()
{
	return (12);
}

__kernel void hello(__global t_complex* a)
{
	a[0].real += test();
	a[0].imag = a[0].imag + 10;
	a[1] = test2(a[0]);
	a[2] = ft_cplx_pow(a, 12345678);
}

