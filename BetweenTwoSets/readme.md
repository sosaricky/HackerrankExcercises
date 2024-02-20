# Beetween Two Sets

## Problema

Se tienen dos arrays a y b . Se quiere saber cuantos números enteros cumplen las siguientes condiciones.

1 - Los elementos del primer array son todos *factores* del entero considerado.
2 - El entero considerado es un *factor* de todos los elementos del segundo array.

Estas dos condiciones se pueden escribir de una manera distinta haciendo énfasis más en el concepto de *divisor* que de *factor*
1 - Todos los elementos del primer array son *divisores* del entero considerado.
2 - Todos los elementos del segundo array son *divisibles* por el entero considerado.


Tenemos infinitos enteros para probar si cumplen las condiciones 1 y 2.¿Hay alguna restricción.....?

Sí la hay!

La condición 1 implica que si al menos uno de los elementos del primer array es mayor que el entero considerado la condición no cumplirá y por lo tanto será descartado.

La condición 2 implica que si al menos un elemento del segundo array es menor que el entero considerado entonces la condición no se cumple y por lo tanto será descartado.

Teniendo en cuenta esto podemos acotar la lista de candidatos(enteros) sobre los cuales testear las condiciones 1 y 2.

Esta lista de enteros va desde el máximo del array a , hasta el máximo del array b.

Hecho esto solo queda por recorrer la lista de candidatos y testear las condiciones 1 y 2 a cada candidato (esto implica recorrer los array a y b en el proceso.)

