#include <stdio.h>

unsigned long long fibonacci(unsigned int n) {
    // Базові випадки
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Рекурсивний випадок
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Введіть номер числа Фібоначчі (0-93): ");
    scanf("%d", &n);

    if (n < 0 || n > 93) {
        printf("Будь ласка, введіть число в діапазоні 0-93.\n");
        return 1;
    }

    printf("Число Фібоначчі №%d дорівнює %llu\n", n, fibonacci((unsigned)n));
    return 0;
}
