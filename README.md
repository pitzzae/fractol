# Fract’ol

Ce projet consiste à créer un petit logiciel d’exploration fractale. 

* Le logiciel proposer plusieur types de fractales di érentes, l’ensemble de Julia et l’ensemble de Mandelbrot

* La molette de la souris permet de zoomer et dézoomer sur la position actuelle de la souris, et cela de façon quasi infinie (modulo les limites de la machine).
* Jeu de couleur ressentir la profondeur de chaque fractale.
* Un paramètre est passé en ligne de commande pour définir quel type de fractale est à a cher. Si il n’y a pas de paramètre fourni, ou si le paramètre est invalide, le programme a che la liste des paramètres disponibles et quitte.
* La touche ESC permettra de quitter le programme.

./fractol `option`

```
-option:
	julia
	julia1
	julia2
	julia3
	julia4
	mandelbrot
	mandelbrot1
	mandelbrot2
```

* julia

![img/julia1](https://github.com/pitzzae/fractol/blob/master/img/julia1.png?raw=true)

* mandelbrot

![img/mandelbrot1](https://github.com/pitzzae/fractol/blob/master/img/mandelbrot1.png?raw=true)