# Repeated String

## Problema

Dado un string "s" y un número "n" se quiere saber cuantas veces aparece la letra "a" en las primeras "n" letras de las infinitas repeticiones del string s.

```powershell
Ejemplo :
s = "acd"
string con las infinitas repeticiones = "acdacdacdacdacdacd ....."
n = 4
apariciones de la letra "a" en los primeros 4 caracteres = 2
```

### Restricciones

- Las letras que forman el string "s" son todas minúsculas y referidas al alfabeto en Inglés.

- $- 1 \le tamanio(s) \le 100$

- $ 1 \le n \le 10^{12}$

## Estrategia

Lo que hace resulta "molesto" es que se hable de un string infinito.Pero en realidad esto no nos importa, ya que  solamente nos interesan *las primeras n letras* de ese string infinito.

Podemos pensar lo siguiente :

- Armamos repeticiones de "s" hasta llegar a la cantidad de "n" caracteres. Tenemos dos posibilidades:

  - En un largo de "n" caracteres nos entran una cantidad entera de veces el string "s".

  - En un largo de "n" caracteres entra una cierta cantidad de veces el string "s" , pero luego nos sobran caracteres que no llegan a armar una repetición de "s".

Luego podemos calcular la cantidad de veces que aparece la letra "a" en los primeros "n" caracteres de las infinitas repeticiones de la siguiente manera:

- Si se da la posibilidad 1 , entonces será la cantidad de veces que aparezca  en "s" multiplicada por "n".

- Si se da la segunda posibilidad entonces será la cantidad de veces que aparezca en "s" multiplicada por "n-x" , donde x es la cantidad de caracteres que sobraron y no pudieron formar parte de una repetición de "s".A la cantidad anterior se debe sumar la cantidad de veces que aparezca "a" en el substring s[1:x].

Luego solo queda codficarlo ....