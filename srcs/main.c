#include "../includes/so_long.h"

// mlx_init / mlx_connection / mlx_loop(mlx_connection) / 

void	so_long(t_data *data)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx) * 1);
	data->mlx = mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		free_and_exit("mlx init failed", EXIT_FAILURE, data, false);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (data->map_x_length + 1) * IMAGE_SIZE,
			(data->map_y_length + 1) * IMAGE_SIZE, "So_long");
	if (mlx->win_ptr == NULL)
		free_and_exit("window opening failed", EXIT_FAILURE, data, false);
	set_images(mlx, data);
	mlx_hook(mlx->win_ptr, 2, 02, move, data);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	ft_free((void **)&mlx->mlx_ptr);
	ft_free((void **)&mlx);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_player	*player;

	if (argc != 2)
		return (1);
	data = malloc(sizeof(t_data) * 1);
	player = malloc(sizeof(t_player) * 1);
	init_data(data, player, argv);
	so_long(data);
}