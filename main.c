/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:11:09 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/11 14:35:13 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game  game;
    
    // 1. Vérification des arguments
    if (ac != 2)
    {
        ft_printf("Error\nUsage: ./so_long maps/map.ber\n");
        return (EXIT_FAILURE);
    }
    
    // 2. Initialisation de la structure à zéro
    ft_memset(&game, 0, sizeof(t_game));
    printf("--- Démarrage du jeu ---\n");

    // 3. Parsing de la carte
    if (parse_map(av[1], &game) == EXIT_FAILURE)
    {
        printf("Erreur: Impossible de lire ou valider la carte .ber\n");
        return (1);
    }
    printf("1. Carte chargée avec succès (%dx%d)\n", game.map.width, game.map.height);
    
    // 4. Vérification du chemin (Flood Fill)
    if (flood_fill(&game) == EXIT_FAILURE)
    {
        printf("Erreur: La carte n'est pas réalisable (chemin bloqué)\n");
        // Ici, tu devrais libérer la map grid avant de quitter
        return (1);
    }
    printf("2. Vérification Flood Fill: OK\n");
    
    // 5. Initialisation de la MLX (Très important de le faire AVANT les textures)
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        printf("Erreur: Échec de mlx_init()\n");
        return (1);
    }

    // 6. Initialisation du jeu (Fenêtre + Textures)
    if (init_game(&game) == EXIT_FAILURE)
    {
        printf("Erreur: Échec de init_game (Fenêtre ou fichiers .xpm manquants)\n");
        return (close_window(&game));
    }
    printf("3. Fenêtre et textures chargées: OK\n");
    
    // 7. Rendu initial
    render_map(&game);
    printf("4. Premier rendu de la map: OK\n");
    
    // 8. Configuration des Events (Hooks)
    mlx_key_hook(game.win, keypress, &game);
    mlx_hook(game.win, 17, 0, close_window, &game); // Croix rouge de la fenêtre
    
    // 9. Lancement de la boucle infinie
    printf("5. Lancement de mlx_loop... Le jeu est prêt !\n");
    mlx_loop(game.mlx);
    
    return (0);
}