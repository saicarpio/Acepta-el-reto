#include <iostream>
#include <iomanip>
#include <fstream>

/*
    Queremos contar cuántas parejas de enteros positivos (x, y) cumplen:
        1/k = 1/x + 1/y

    1) Eliminamos denominadores:
        1/x + 1/y = (x + y) / (x*y)
        => 1/k = (x + y) / (x*y)
        => x*y = k*(x + y)

    2) Pasamos todo a un lado:
        x*y - k*x - k*y = 0

    3) Sumamos k^2 a ambos lados para poder factorizar:
        x*y - k*x - k*y + k^2 = k^2
        (x - k)(y - k) = k^2

    4) Cambio de variables:
        a = x - k
        b = y - k
        => a * b = k^2
        con a > 0, b > 0

    El problema original se transforma en:
        "¿Cuántas parejas de divisores positivos (a, b) existen tales que
         a * b = k^2?"

    5) Cada divisor positivo 'a' de k^2 determina exactamente un
       b = k^2 / a, y una solución:
            x = a + k
            y = b + k

    6) El número total de divisores positivos de k^2 es:
        d(k^2)

       Pero las parejas (a, b) y (b, a) generan las mismas soluciones
       (x, y) y (y, x), que deben contarse una sola vez.

    7) Por tanto, el número final de soluciones es:
        (d(k^2) + 1) / 2

    Este es el valor que calcula esta función.
*/

unsigned long long resolver(int n) {

    // Pasamos n a unsigned long long para evitar desbordamientos
    // al trabajar con k^2 y con productos grandes
    // 'temp' es una copia de n que iremos dividiendo
    // hasta factorizar completamente el número
    unsigned long long temp = (unsigned long long)n;

    // 'prod' acabará siendo el número total de divisores de k^2
    // Inicializamos a 1 porque vamos a multiplicar factores
    unsigned long long prod = 1ULL;

    // Recorremos posibles divisores p empezando en 2
    // Solo necesitamos llegar hasta sqrt(temp):
    // si temp tuviera un divisor mayor, tendría otro menor ya probado
    for (unsigned long long p = 2; p * p <= temp; ++p) {

        // Si p divide a temp, entonces p es un factor primo de n
        if (temp % p == 0) {

            // Contaremos cuántas veces aparece este primo p
            // en la factorización de n
            unsigned long long cnt = 0;

            // Dividimos tantas veces como podamos entre p
            // Cada división aumenta el exponente del primo p
            while (temp % p == 0) {
                temp /= p;
                ++cnt;
            }

            // Si en k el primo p aparece cnt veces:
            //     k = ... * p^cnt * ...
            // entonces en k^2 aparecerá:
            //     p^(2*cnt)
            //
            // Los divisores de k^2 pueden elegir el exponente de p entre:
            //     0, 1, 2, ..., 2*cnt
            //
            // Eso son (2*cnt + 1) opciones
            prod *= (2 * cnt + 1);
        }
    }

    // Si al terminar el bucle temp > 1, significa que:
    // - queda exactamente UN primo sin factorizar
    // - ese primo aparece una sola vez en k
    //
    // Ejemplo: k = 14 -> temp = 7
    //
    // En k^2 ese primo aparece como p^2,
    // lo que aporta 3 posibles exponentes: 0, 1, 2
    if (temp > 1) {
        prod *= 3;   // (2*1 + 1)
    }

    // 'prod' es ahora el número total de divisores positivos de k^2
    //
    // Cada divisor 'a' genera una solución:
    //     (x - k)(y - k) = k^2
    //
    // Pero (x, y) y (y, x) representan la misma pareja,
    // así que contamos solo la mitad.
    //
    // El divisor central (a = b) cuenta una sola vez,
    // por eso usamos (prod + 1) / 2
    // Sumo 1 para contar el caso en que a = b
    // y luego divido entre 2 para evitar contar dos veces las parejas simétricas
    return (prod + 1) / 2ULL;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (! std::cin)
        return false;
    
    unsigned long long sol = resolver(n);

    std::cout << sol << "\n";
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}