# Sokoban

Bonjour,

Avant de vous expliquez le but du jeu et son fonctionnement, je vous invite à installer ncurses (sudo apt-get install libncurses5-dev).

Je vous présente mon Sokoban, qui consiste à pousser les 'X' (dans un Sokoban classique les 'X' représentent des boites)
sur des 'O' (qui représentent l'emplacement où doivent aller les boites).
Les '#' représentent les limites de la map et le 'P' représente l'emplacement du joueur.
Pour vous déplacez, il faut utiliser les flèches du clavier (flèches du haut pour aller en haut, flèches du bas pour aller en bas,
flèches de droite pour aller à droite et flèches de gauche pour aller à gauche).

Le jeu se termine quand tout les 'O' sont recouverts par les 'X'ou quand vous ne pouvez plus bouger les 'X'.

ATTENTION : pour lancer le jeu il faut qu'il y ait autant de 'X' que de 'O' et il faut seulement un 'P'
Pour lancer le sokoban, faire "make" pour avoir le ./my_sokoban puis rentrer sur le terminal ./my_sokoban le_nom_de_ma_map.

Vous trouverez un exemple de map dans le dossier maps.

Bon jeu !