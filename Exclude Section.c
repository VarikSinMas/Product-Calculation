#include <stdio.h>
const float PUNTOSxEURO = 0.25;

int main() {

    int producto, producto_max = 0, n = 0, producto_actual = 0;
    float precio, precio_max = 0, precio_min = 0, total = 0, total_sin_perfumeria = 0, media = 0;
    int codigos[999] = {0}; // Array para almacenar los códigos de producto ingresados

    printf("Ingrese el codigo de producto y su precio (0 para terminar):\n");
    printf("Añade máximo de productos: ");
    scanf("%d", &producto_max);

    do {
        printf("Añade producto: ");
        scanf("%d", &producto_actual);

        // Comprobar si el código de producto ya ha sido ingresado
        if (codigos[producto_actual] == 0 && producto_actual != 0) {
            printf("Añade precio: ");
            scanf("%f", &precio);

            if (producto_actual < 300 || producto_actual > 450) {
                total_sin_perfumeria += precio;
            }

            total += precio;
            codigos[producto_actual] = 1; // Marcar el código de producto como ingresado

            if (n == 0) {
                precio_min = precio;
                n++;
            }

            if (precio > precio_max) {
                precio_max = precio;
                producto = producto_actual;
            }

            if (precio < precio_min) {
                precio_min = precio;
            }

            n++;
        }
        else {
            printf("El código de producto ya ha sido ingresado o no es válido.\n");
        }

    } while (n <= producto_max);

    media = total_sin_perfumeria / (n - 1);

    printf("El total es: %.2f euros\n", total);
    printf("El total sin perfumería es: %.2f euros\n", total_sin_perfumeria);
    printf("El promedio de productos sin perfumería es: %.2f euros\n", media);
    printf("El producto más caro es el %d, con un precio de %.2f euros\n", producto, precio_max);
    printf("El producto más barato tiene un precio de %.2f euros\n", precio_min);
    printf("Acumulaste %.2f puntos por tu compra\n", PUNTOSxEURO * total);

    return 0;
}





