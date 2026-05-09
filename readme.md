#### *This project has been created as part of the 42 curriculum by cn-goie.*

# SO_LONG

Petit jeu 2D réalisé avec MiniLibX (projet 42). Le joueur doit récupérer toutes les collectibles puis atteindre la sortie.

## Installation

- Cloner le projet puis, à la racine, lancer `make` pour compiler `so_long`.

## Lancer le jeu

- Compilation : Compilez le projet avec la commande make.

- Lancement : Exécutez le programme via ./so_long [carte].ber.

- Maintenance : Utilisez make clean pour supprimer les fichiers objets ou make fclean pour réinitialiser complètement le répertoire.

## Contrôles

- Déplacements: W/A/S/D ou les fleches.
- Quitter: Esc ou fermer la fenêtre.

## Cartes

- Emplacement : Les fichiers de configuration de cartes utilisent l'extension .ber et sont regroupés dans le répertoire maps/.

- Génération : Un script utilitaire nommé generate.sh permet de créer dynamiquement de nouveaux niveaux.

- Contraintes de validité : Pour être acceptée, une carte doit être rectangulaire, parfaitement close par des murs, et comporter au moins une sortie (E), un point de départ (P) ainsi qu'un objet à collecter (C).
