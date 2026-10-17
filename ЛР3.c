#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void task1() {
    int m, n;
    printf("\nTask 1\n");
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Error\n");
    }
    else if (m % n == 0) {
        printf("Chastka: %d\n", m / n);
    }
    else {
        printf("%d ne dilytsya na %d nacilo\n", m, n);
    }
}

void task33() {
    int a, b, c, k;
    printf("\nTask 33\n");
    printf("Enter a, b, c, k: ");
    scanf("%d %d %d %d", &a, &b, &c, &k);

    if (k == 0) {
        printf("k = 0, Error\n");
        return;
    }

    printf("k dilytsya: ");
    int found = 0;
    if (a % k == 0) {
        printf("a ");
        found = 1;
    }
    if (b % k == 0) {
        printf("b ");
        found = 1;
    }
    if (c % k == 0) {
        printf("c ");
        found = 1;
    }
    if (!found) {
        printf("nichogo");
    }
    printf("\n");
}

void task40() {
    double t;
    printf("\nTask 40\n");
    printf("Temperatura: ");
    scanf("%lf", &t);

    if (t > 60)
        printf("Pozhezhnonebezpechna situaciya!\n");
    else
        printf("Temperatura normalna\n");
}

void task51() {
    int x, y;
    printf("\nTask 51\n");
    printf("Dva chysla: ");
    scanf("%d %d", &x, &y);

    if (x % 2 == 0 && y % 2 == 0)
        printf("Obydva parni\n");
    else if (x % 2 != 0 && y % 2 != 0)
        printf("Obydva neparni\n");
    else if (x % 2 == 0)
        printf("Pershe parne, druge ni\n");
    else
        printf("Pershe ni, druge parne\n");
}

void task54() {
    double a, b, c;
    printf("\nTask 54\n");
    printf("Storony tricutnyka: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Ne tricutnyk\n");
        return;
    }

    double a2 = a * a, b2 = b * b, c2 = c * c;

    if (fabs(a2 + b2 - c2) < 0.001 || fabs(a2 + c2 - b2) < 0.001 || fabs(b2 + c2 - a2) < 0.001) {
        printf("Pryamokutniy\n");
    }
    else {
        double cosC = (a2 + b2 - c2) / (2 * a * b);
        if (cosC > 1) cosC = 1;
        if (cosC < -1) cosC = -1;
        double angle = acos(cosC) * 180 / 3.14159;
        printf("Ne pryamokutniy. Kut C ≈ %.1f gradusiv\n", angle);
    }
}

void task58() {
    double x1, y1, x2, y2, x3, y3;
    printf("\nTask 58\n");
    printf("Tochka A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Tochka B: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Tochka C: ");
    scanf("%lf %lf", &x3, &y3);

    double bx1 = x1 - x2;
    double by1 = y1 - y2;
    double bx2 = x3 - x2;
    double by2 = y3 - y2;

    double cross = bx1 * by2 - by1 * bx2;

    if (fabs(cross) < 0.0001) {
        printf("Tochky na odniy ptyamiy\n");
    }
    else {
        double dot = bx1 * bx2 + by1 * by2;
        double len1 = sqrt(bx1 * bx1 + by1 * by1);
        double len2 = sqrt(bx2 * bx2 + by2 * by2);

        if (len1 < 0.0001 || len2 < 0.0001) {
            printf("Tochky zbigayutsya\n");
            return;
        }

        double cosB = dot / (len1 * len2);
        if (cosB > 1) cosB = 1;
        if (cosB < -1) cosB = -1;

        double angle = acos(cosB) * 180 / 3.14159;
        printf("Kut pry B = %.1f gradusiv\n", angle);
    }
}

void task62() {
    double a, b;
    printf("\nTask 62\n");
    printf("Rivnyanya a^3 + b*x = 0\n");
    printf("a і b: ");
    scanf("%lf %lf", &a, &b);

    if (fabs(b) < 1e-9) {
        if (fabs(a) < 1e-9)
            printf("Bud-yakyi x pidhodyt\n");
        else
            printf("Nema rishen\n");
    }
    else {
        double x = -(a * a * a) / b;
        printf("x = %g\n", x);
    }
}

void task77() {
    double x[4], y[4];
    int i;
    printf("\nTask 77\n");
    printf("Enter 4 vershyny:\n");

    for (i = 0; i < 4; i++) {
        printf("%d-а vershyna: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    int plus = 0, minus = 0;

    for (i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        int k = (i + 2) % 4;

        double ax = x[j] - x[i];
        double ay = y[j] - y[i];
        double bx = x[k] - x[j];
        double by = y[k] - y[j];

        double cr = ax * by - ay * bx;

        if (cr > 0.0001) plus = 1;
        if (cr < -0.0001) minus = 1;
    }

    if (plus && minus)
        printf("Ne opuklyi\n");
    else
        printf("Opuklyi\n");
}

void task101() {
    double px, py, x1, y1, x2, y2, x3, y3;
    printf("\nTask 101\n");
    printf("Tochka: ");
    scanf("%lf %lf", &px, &py);
    printf("Vershyny trykutnika:\n");
    printf("1: "); scanf("%lf %lf", &x1, &y1);
    printf("2: "); scanf("%lf %lf", &x2, &y2);
    printf("3: "); scanf("%lf %lf", &x3, &y3);

    double d = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);

    if (fabs(d) < 1e-9) {
        printf("Trykutnik virodzhenyi\n");
        return;
    }

    double a = ((y2 - y3) * (px - x3) + (x3 - x2) * (py - y3)) / d;
    double b = ((y3 - y1) * (px - x3) + (x1 - x3) * (py - y3)) / d;
    double c = 1 - a - b;

    if (a >= -0.0001 && b >= -0.0001 && c >= -0.0001)
        printf("Tochka vseredyni (abo na mezhi)\n");
    else
        printf("Tochka zovni\n");
}

void task110() {
    double a, b, c;
    printf("\nTask 110\n");
    printf("Tri chisla: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double max = a, min = a;

    if (b > max) max = b;
    if (c > max) max = c;
    if (b < min) min = b;
    if (c < min) min = c;

    printf("Max: %g\n", max);
    printf("Min: %g\n", min);
}

int main() {
    int choice;

    do {
        printf("\n----- Lab robota 3 -----\n");
        printf("1. Task 1\n");
        printf("2. Task 33\n");
        printf("3. Task 40\n");
        printf("4. Task 51\n");
        printf("5. Task 54\n");
        printf("6. Task 58\n");
        printf("7. Task 62\n");
        printf("8. Task 77\n");
        printf("9. Task 101\n");
        printf("10. Task 110\n");
        printf("0. Exit\n");
        printf("Vybir: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: task1(); break;
        case 2: task33(); break;
        case 3: task40(); break;
        case 4: task51(); break;
        case 5: task54(); break;
        case 6: task58(); break;
        case 7: task62(); break;
        case 8: task77(); break;
        case 9: task101(); break;
        case 10: task110(); break;
        case 0: printf("Kinec\n"); break;
        default: printf("Nema takogo punktu\n");
        }

    } while (choice != 0);

    return 0;
}