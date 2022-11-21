### Análsis de MissingNumbers from Hackerrank.

Este ejercicio tiene algunas cosas interesantes respecto a la complejidad algorítmica que tiene que tener la solución.

Primero el enunciado : 

Tenemos dos arrays , a uno se lo mencionará como "first" y al otro como "second" . Y sus nombres serán "arr" y "brr" respectivamente.
El objetivo es averiguar que elementos que están en second no están en first, o bien cuya cantidad de repeticiones no es la misma en ambos arrays. A estos elementos los guardaremos en orden creciente en un array "missing" y solo debe incluirse una única vez.
Pero no es tan simple, además de esto también son candidatos a estar en missing los elementos que cumplan con lo siguiente:


*

Restricciones:
- $n =$ longitud de arr
- $m =$ longitud de brr
- $1 \leq n,m \leq 2.10⁵$
- $n \leq m$
- $1 \leq brr[i] \leq 10^4$
- $max(brr)-min(arr) \leq 100$
 Este dato no lo supe aprovechar, pero debe servir para acotar algo.

 Como se ve en las restricciones las longitudes de array que pueden darse son muy grandes. Por lo que los algoritmos que usemos de búsqueda,ordenamiento y en general deben tener buena complejidad algorítmica.

UNA solución a este problema puede ser la siguiente : 

- Iterar por cada elemento de brr. En cada iteración contar las veces que el elemento brr[i] aparece en brr y en arr. Luego comparar los resultados del conteo para cada array . Si son distintos , se debe agregar a missing.Para comprobar que no lo hayamos agregado antes lo buscamos en missing.

El algoritmo sería el siguiente : (*)
```cpp
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    vector<int> missing;
    int matchesInFirst,matchesInSecnd;
   
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
       
    for(unsigned int i = 0;i<brr.size();i++){
        matchesInFirst = countMatches(arr,brr[i]);
        matchesInSecnd = countMatches(brr,brr[i]);
        if(matchesInFirst != matchesInSecnd && binarySearch(missing,brr[i]) == -1){
            missing.push_back(brr[i]);
        }
    }
    
    return missing;

}

```
Este algoritmo usa countMatches(vector<int>,int); 
```cpp 
int countMatches(vector<int> arr, int x)
{
    int ind = binarySearch(arr,x);
 
    // If element is not present
    if (ind == -1)
        return 0;
 
    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
 
    // Count elements on right side.
    int right = ind + 1;
    while (right < arr.size() && arr[right] == x)
        count++, right++;
 
    return count;
}
```
Este algoritmo de conteo es una mejora de algoritmo más "normal" que barre completamenta el array para encontrar todas las coincidencias.La precondición es que el array ya debe venir ordenado (sino no podríamos usar la busqueda binaria). Entonces primero encuentra una coincidencia con búsqueda binaria y luego barre hacia atrás y adelante donde estarán sus demás coincidencias.La mejora es que ya encontrar la primera coincidencia las demás estarán en su alrededor y no tendremos que barrer el array completo.

El algoritmo de búsqueda binaria es el siguiente  

```cpp
int binarySearch(vector <int> arr, int value){
    int firstIndex = 0 , lastIndex = arr.size()-1;
    int  centralIndex = (firstIndex+lastIndex)/2;
    while(firstIndex<=lastIndex && arr[centralIndex] != value){
        // Tengo que buscar a la derecha.
        if(value > arr[centralIndex]){
            // inicio = central+1, final no cambia.
            firstIndex = centralIndex+1 ;
        // Tengo que buscar a la izquierda.
        }else{
            // final = central-1
            lastIndex = centralIndex-1;
        }
        centralIndex = (firstIndex+lastIndex)/2;
    }
    return firstIndex > lastIndex ? -1 : centralIndex;
}
```

Si tomamos esto (*) como solución hackerrank no dará para uno de los test un msj con lo siguiente.
>"Time limit exceeded
>Your code did not execute within the time limits. Please optimize your code. For more information on execution time limits, refer to the >environment page"

Entonces una solución es hacer que el algoritmo no tenga que buscar las coincidencias de un caracter si ya lo hizo antes.Para eso guardamos los que hayamos procesado en array auxiliar que llamamos processed.El algoritmo queda de la siguiente manera.

```cpp
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    vector<int> missing;
    vector<int> processed;
    int matchesInFirst,matchesInSecnd;
   
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
      
    for(unsigned int i = 0;i<brr.size();i++){
        // If not processed yet,count matches in first array (arr)
        if(binarySearch(processed,brr[i]) == -1){
            matchesInFirst = countMatches(arr,brr[i]);
            matchesInSecnd = countMatches(brr,brr[i]);
            // Add current element to processed
            processed.push_back(brr[i]);
            if(matchesInFirst != matchesInSecnd && binarySearch(missing,brr[i]) == -1){
                missing.push_back(brr[i]);
            }
        }
    }

    return missing;

}
```
Otra estrategia es aprovechar que sabemos que $max(brr) - min(arr) \leq 100$ y entonces guardar en un array de 100 posiciones , donde cada posición corresponde a un elemento de ese intervalo, la cantidad de coincidencias que hay de cada elemento entre max y min. Esto se conoce como "caching"