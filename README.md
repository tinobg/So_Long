# so_long

**so_long** est un petit jeu 2D réalisé en C avec MiniLibX dans le cadre du cursus **École 42**.  
Le joueur doit collecter tous les objets de la carte avant de rejoindre la sortie, sans traverser les murs.

Projet d’introduction à la **programmation graphique**, à la gestion d’événements et au rendu d’un environnement 2D.

---

## 🎮 Gameplay

- Contrôles : `W`, `A`, `S`, `D` (ou flèches)
- Objectifs :
  ✅ Collecter tous les items  
  ✅ Rejoindre la sortie une fois les items récupérés  
- Affichage du nombre de mouvements dans le terminal
- Collision avec les murs
- Fermeture propre via `ESC` ou la croix fenêtre

---

## 🗺️ Format de la carte (`.ber`)

Caractères autorisés :
| Symbole | Signification |
|---------|--------------|
| `1` | Mur |
| `0` | Sol |
| `C` | Collectible |
| `E` | Sortie |
| `P` | Joueur |

📌 Contraintes de validation :
- Rectangle obligatoire
- Entourée de murs
- Exactement **1 sortie** et **1 spawn joueur**
- Au moins **1 collectible**
- Chemin **obligatoirement valide** entre P → collectibles → E

Exemple de map:
1111111
1P0C0E1
1111111


---

## 🖼️ Graphismes

- Rendu top-down en 2D
- Sprites fixes avec MiniLibX (`.xpm`)
- Gestion fluide de la fenêtre et des événements

---

## ⚙️ Compilation & Exécution

```sh
make
./so_long maps/map.ber

Pour nettoyer:
make clean
make fclean
make re
