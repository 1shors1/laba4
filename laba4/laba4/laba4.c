#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

void task1() {
    int num_districts;
    double pop, area;
    double total_pop = 0.0, total_area = 0.0;

    printf(" Завдання 102:\n");

    printf("Введiть кiлькiсть районiв у областi: ");
    scanf_s("%d", &num_districts);

    if (num_districts <= 0) {
        printf("Помилка: Кiлькiсть районiв має бути додатним числом!\n\n");
        return;
    }

    for (int i = 1; i <= num_districts; i++) {
        printf("Район %d - введiть кiлькiсть жителiв (у тис. чол.) та площу (в кв. км): ", i);
        scanf_s("%lf %lf", &pop, &area);

        if (pop < 0 || area <= 0) {
            printf("Помилка: Кiлькiсть жителiв не може бути вiд'ємною, а площа має бути додатною!\n\n");
            return;
        }

        total_pop += pop;
        total_area += area;
    }

    double avg_density = (total_pop * 1000.0) / total_area;

    printf("Загальне населення: %.2lf тис. чол.\n", total_pop);
    printf("Загальна площа: %.2lf кв. км\n", total_area);
    printf("Середня щiльнiсть населення областi: %.2lf чол./кв. км\n\n", avg_density);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void task2() {
    printf(" Завдання 109:\n");

    bool all_prime = true;

    for (int x = 0; x <= 15; x++) {
        int res = x * x + x + 17;
        bool prime = isPrime(res);

        printf("x = %2d  ->  x^2 + x + 17 = %3d  ->  %s\n", x, res, prime ? "Просте" : "Не є простим");

        if (!prime) {
            all_prime = false;
        }
    }

    if (all_prime) {
        printf("\nВисновок: Твердження Є правильним для всiх x в [0, 15].\n\n");
    }
    else {
        printf("\nВисновок: Твердження НЕ є правильним для всiх x в [0, 15].\n\n");
    }
}

void task3() {
    printf(" Завдання 128:\n");

    bool found = false;

    for (int num = 10; num <= 99; num++) {
        int tens = num / 10;
        int units = num % 10;

        if (num == (units * units + tens * tens * tens)) {
            printf("Знайдено двозначне число: %d (десятки = %d, одиницi = %d -> %d^2 + %d^3 = %d + %d = %d)\n",
                num, tens, units, units, tens, units * units, tens * tens * tens, num);
            found = true;
        }
    }

    if (!found) {
        printf("Такого двозначного числа не існує.\n");
    }
    printf("\n");
}

void task4() {
    long long n;
    int m;
    long long temp;
    int digit_count = 0;
    int sum = 0;

    printf(" Завдання 165:\n");

    printf("Введiть натуральне число n: ");
    scanf_s("%lld", &n);

    printf("Введiть m (кiлькiсть останнiх цифр для суми): ");
    scanf_s("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Помилка: n та m мають бути додатними цiлими числами!\n\n");
        return;
    }

    temp = n;
    while (temp > 0) {
        digit_count++;
        temp /= 10;
    }

    if (m > digit_count) {
        printf("Помилка: m (%d) не може бути бiльшим за загальну кiлькiсть цифр (%d)!\n\n", m, digit_count);
        return;
    }

    temp = n;
    for (int i = 0; i < m; i++) {
        sum += temp % 10;
        temp /= 10;
    }

    printf("Сума останнiх %d цифр числа %lld дорiвнює: %d\n\n", m, n, sum);
}

void task5() {
    double eps;

    printf(" Завдання 226 (220.a):\n");

    printf("Введiть точнiсть epsilon (> 0): ");
    scanf_s("%lf", &eps);

    if (eps <= 0) {
        printf("Помилка: Epsilon має бути додатним числом!\n\n");
        return;
    }

    int n = 1;
    double a_prev = 1.0;
    double a_curr = a_prev;

    printf("\nЕлементи послiдовностi:\n");
    printf("a[%d] = %.10lf\n", n, a_prev);

    while (fabs(a_curr * a_curr - 2.0) >= eps) {
        n++;
        a_curr = 0.5 * (a_prev + 2.0 / a_prev);
        printf("a[%d] = %.10lf\n", n, a_curr);
        a_prev = a_curr;
    }

    printf("\nНайменший номер n = %d, при якому |a_n^2 - 2| < %.10lf\n\n", n, eps);
}

void task6() {
    int n;
    double P = 1.0;

    printf(" Завдання 37:\n");

    printf("Введiть натуральне число n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Помилка: n має бути додатним цiлим числом!\n\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        P *= (1.0 - 1.0 / (2.0 * i));
    }

    printf("Обчислене добуток P = %.8lf\n\n", P);
}

void task7() {
    long long n, temp;
    int pos = 0;
    int result_pos = 0;

    printf(" Завдання 164:\n");

    printf("Введiть натуральне число n: ");
    scanf_s("%lld", &n);

    if (n <= 0) {
        printf("Помилка: n має бути додатним цiлим числом!\n\n");
        return;
    }

    temp = n;
    while (temp > 0) {
        pos++;
        if (temp % 10 == 3) {
            result_pos = pos;
            break;
        }
        temp /= 10;
    }

    printf("Номер найправiшої цифри '3' вiд кiнця числа: %d\n\n", result_pos);
}

void task8() {
    int current_term = 4;
    int sum = current_term;

    printf(" Завдання 53:\n");

    for (int i = 3; i <= 10; i++) {
        current_term *= 2;
        sum += current_term;
    }

    printf("Сума 2^2 + 2^3 + ... + 2^10 = %d\n\n", sum);
}

void task9() {
    int val;
    int prev_val;
    int unique_count = 1;
    int max_repeats = 1;
    int curr_repeats = 1;

    printf(" Завдання 270:\n");

    printf("Введiть неспадаючу послiдовнiсть цiлих чисел, що закiнчується числом 1000:\n");
    scanf_s("%d", &val);

    prev_val = val;

    while (val != 1000) {
        scanf_s("%d", &val);

        if (val < prev_val) {
            printf("Помилка: Послiдовнiсть має бути неспадаючою!\n\n");
            return;
        }

        if (val == prev_val) {
            curr_repeats++;
        }
        else {
            unique_count++;
            if (curr_repeats > max_repeats) {
                max_repeats = curr_repeats;
            }
            curr_repeats = 1;
        }

        prev_val = val;
    }

    if (curr_repeats > max_repeats) {
        max_repeats = curr_repeats;
    }

    printf("Максимальна кiлькiсть чисел, що йдуть поспiль i рiвнi мiж собою: %d\n", max_repeats);
    printf("Кiлькiсть рiзних чисел у послiдовностi: %d\n\n", unique_count);
}

void task10() {
    double a = 1.0;
    double b = -2.0;

    printf(" Завдання 261:\n");
    printf("      x      |      y      \n");
    printf("---------------------------\n");

    for (double x = -1.0; x <= 5.0 + 1e-9; x += 0.5) {
        double denom1 = 2.0 * a - b * x;
        double denom2 = fabs(a - x);

        if (fabs(denom1) < 1e-9 || fabs(denom2) < 1e-9) {
            printf("  %7.2lf    |  Невзначено (дiлення на 0)\n", x);
            continue;
        }

        double rad_val = (2.0 * a - atan(x)) / denom2;

        if (rad_val < 0.0) {
            printf("  %7.2lf    |  Невизначено (корень < 0)\n", x);
            continue;
        }

        double term1 = (0.3 * a * b * x) / denom1;
        double term2 = 3.0 * sqrt(rad_val);
        double y = term1 - term2;

        printf("  %7.2lf    |  %11.6lf\n", x, y);
    }
    printf("\n");
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();

    return 0;
}