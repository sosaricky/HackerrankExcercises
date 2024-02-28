# Day of Programmer

## Problema

Se quiere saber cual la fecha completa en formato dd.mm.yyyy del 256 avo día del año en Rusia, dado cierto año.

El año que se tiene como input está en rango de [1700,2700].

### Restricciones

Tener en cuenta que desde 1700 a 1917 en Rusia se usó el Julian Calendar, mientras que desde 1919 se usa el Gregorian Calendar.

Ambos calendarios tienen la misma cantidad de días en cada mes , sin embargo el criterio para determinar si un año es un bisiesto (leap year) difiere en cada uno.
    - Julian Calendar : el año es bisiesto si es divisible por 4.
    - Gregorian Calendar : el año es bisiesto si es divisible por 400 o bien , si es divisible por 4 y no divisible por 100.

Por último, se debe tener en cuenta también que la transición entre ambos calendarios sucedió en 1918 de la siguiente manera.
    - Luego del 31 de enero , el día siguiente fue el 14 de febrero.
    - El 14 de febrero fue entonces el 32avo día del año 1918.
