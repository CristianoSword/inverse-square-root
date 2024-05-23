#include <stdio.h>

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;             // Interpreta bits de float como inteiro
    i = 0x5f3759df - (i >> 1);  // Mágica do número
    y = *(float*)&i;            // Interpreta bits de inteiro como float
    y = y * (threehalfs - (x2 * y * y)); // 1ª iteração de Newton

    return y;
}

int main() {
    float number;

    printf("Digite um número: ");
    scanf("%f", &number);

    if (number > 0) {
        float result = Q_rsqrt(number);
        printf("A raiz quadrada inversa rápida de %f é %f\n", number, result);
    } else {
        printf("Por favor, digite um número positivo.\n");
    }

    return 0;
}
