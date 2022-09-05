#include <../mlx_linux/mlx.h>
#include <stdio.h>
#include <stdlib.h>

struct s_mlx
{
	void	*mlx;
	void	*win;
};


int	ft_bolo(int keycode, struct s_mlx *mlx)
{
	if(keycode == 65307)
	{
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		if (mlx->mlx)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
		exit(0);
	}
	return (0);
}

int	main(void)
{
	static struct s_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 300, 300, "Hello world!");
	mlx_hook(mlx.win, 02, (1L<<0), ft_bolo, &mlx);
	mlx_loop(mlx.mlx);
}
