#include <stdio.h>

int main() {
    int estudiantes = 5;
    int asignaturas = 3;
    char estudiantesNombres[5][50];
    char asignaturasNombres[3][50];
    float calificaciones[5][3];
    float promedios[5];
    char entrada[100];
    int i, j;

    printf("Ingrese las asignaturas\n");
    for (j = 0; j < asignaturas; j++) {
        int valido;
        do {
            valido = 1;
            printf("Asignatura #%d: ", j + 1);
            fgets(asignaturasNombres[j], 50, stdin);

            int largo = 0;
            for (int k = 0; asignaturasNombres[j][k] != '\0'; k++) {
                if (asignaturasNombres[j][k] == '\n') {
                    asignaturasNombres[j][k] = '\0';
                    break;
                }
                largo++;
            }

            if (largo == 0) {
                printf("El nombre no puede estar vacío \n");
                valido = 0;
                continue;
            }

        } while (!valido);
    }
    printf("\nIngrese los nombres de los estudiantes\n");
    for (i = 0; i < estudiantes; i++) {
        int valido;
        do {
            valido = 1;
            printf("\nEstudiante #%d: ", i + 1);
            fgets(estudiantesNombres[i], 50, stdin);

            int largo = 0;
            for (int k = 0; estudiantesNombres[i][k] != '\0'; k++) {
                if (estudiantesNombres[i][k] == '\n') {
                    estudiantesNombres[i][k] = '\0';
                    break;
                }
                largo++;
            }

            if (largo == 0) {
                printf("El nombre no puede estar vacío\n");
                valido = 0;
                continue;
            }

            for (int k = 0; estudiantesNombres[i][k] != '\0'; k++) {
                if (estudiantesNombres[i][k] >= '0' && estudiantesNombres[i][k] <= '9') {
                    printf("El nombre no puede contener números\n");
                    valido = 0;
                    break;
                }
            }
        } while (!valido);

        for (j = 0; j < asignaturas; j++) {
            float nota;
            int validoNota = 0;
            do {
                printf("  Ingrese la calificación para la asignatura %s: ", asignaturasNombres[j]);
                fgets(entrada, sizeof(entrada), stdin);

                int esNumero = 1;
                int tieneDecimal = 0;
                for (int k = 0; entrada[k] != '\0' && entrada[k] != '\n'; k++) {
                    if ((entrada[k] < '0' || entrada[k] > '9') && entrada[k] != '.') {
                        esNumero = 0;
                        break;
                    }
                    if (entrada[k] == '.') tieneDecimal++;
                    if (tieneDecimal > 1) {
                        esNumero = 0;
                        break;
                    }
                }
                     int largo = 0;
            for (int k = 0; estudiantesNombres[i][k] != '\0'; k++) {
                if (estudiantesNombres[i][k] == '\n') {
                    estudiantesNombres[i][k] = '\0';
                    break;
                }
                largo++;
            }

            if (largo == 0) {
                printf("El nombre no puede estar vacío\n");
                valido = 0;
                continue;
            }

                if (esNumero) {
                    sscanf(entrada, "%f", &nota);
                    if (nota >= 0.0 && nota <= 10.0) {
                        calificaciones[i][j] = nota;
                        validoNota = 1;
                    } else {
                        printf("Debe estar entre 0 y 10\n");
                    }
                } else {
                    printf("Solo se permiten números\n");
                }
            } while (!validoNota);
        }
    }


    char opcion;
    do {
        printf("\nMENÚ DE OPCIONES\n");
        printf("1. Ver promedios por estudiante\n");
        printf("2. Ver aprobados y reprobados por asignatura\n");
        printf("3. Ver mayor y menor nota por asignatura\n");
        printf("4. Ver aprobados y reprobados por estudiante\n");
        printf("5. Ver mayor y menor nota por estudiante\n");
        printf("6. Ver promedio por asignatura\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcion = entrada[0];

        switch (opcion) {
            case '1':
                printf("\nPromedios por estudiante\n");
                printf("%-20s", "Estudiante");
                for (j = 0; j < asignaturas; j++) printf("%-20s", asignaturasNombres[j]);
                printf("%-15s\n", "Promedio");
                for (i = 0; i < estudiantes; i++) {
                    float suma = 0;
                    printf("%-20s", estudiantesNombres[i]);
                    for (j = 0; j < asignaturas; j++) {
                        printf("%-20.2f", calificaciones[i][j]);
                        suma += calificaciones[i][j];
                    }
                    promedios[i] = suma / asignaturas;
                    printf("%-15.2f\n", promedios[i]);
                }
                break;

            case '2':
                printf("\nAprobados y Reprobados por Asignatura\n");
                for (j = 0; j < asignaturas; j++) {
                    int aprob = 0, reprob = 0;
                    for (i = 0; i < estudiantes; i++) {
                        if (calificaciones[i][j] >= 6.0)
                            aprob++;
                        else
                            reprob++;
                    }
                    printf("%s: Aprobados: %d, Reprobados: %d\n", asignaturasNombres[j], aprob, reprob);
                }
                break;

            case '3':
                printf("\nMayor y Menor Nota por Asignatura\n");
                for (j = 0; j < asignaturas; j++) {
                    float mayor = calificaciones[0][j], menor = calificaciones[0][j];
                    for (i = 1; i < estudiantes; i++) {
                        if (calificaciones[i][j] > mayor) mayor = calificaciones[i][j];
                        if (calificaciones[i][j] < menor) menor = calificaciones[i][j];
                    }
                    printf("%s: Mayor nota: %.2f, Menor nota: %.2f\n", asignaturasNombres[j], mayor, menor);
                }
                break;

            case '4':
                printf("\nAprobados y Reprobados por Estudiante\n");
                for (i = 0; i < estudiantes; i++) {
                    int aprob = 0, reprob = 0;
                    for (j = 0; j < asignaturas; j++) {
                        if (calificaciones[i][j] >= 6.0)
                            aprob++;
                        else
                            reprob++;
                    }
                    printf("%s: Aprobadas: %d, Reprobadas: %d\n", estudiantesNombres[i], aprob, reprob);
                }
                break;

            case '5':
                printf("\nMayor y Menor Nota por Estudiante\n");
                for (i = 0; i < estudiantes; i++) {
                    float mayor = calificaciones[i][0], menor = calificaciones[i][0];
                    for (j = 1; j < asignaturas; j++) {
                        if (calificaciones[i][j] > mayor) mayor = calificaciones[i][j];
                        if (calificaciones[i][j] < menor) menor = calificaciones[i][j];
                    }
                    printf("%s: Mayor nota: %.2f, Menor nota: %.2f\n", estudiantesNombres[i], mayor, menor);
                }
                break;

            case '6':
                printf("\nPromedio por Asignatura\n");
                for (j = 0; j < asignaturas; j++) {
                    float suma = 0;
                    for (i = 0; i < estudiantes; i++) {
                        suma += calificaciones[i][j];
                    }
                    float promedio = suma / estudiantes;
                    printf("%s: Promedio: %.2f\n", asignaturasNombres[j], promedio);
                }
                break;

            case '7':
                printf("Fin del programa\n");
                break;

            default:
                printf("Seleccione una opción del 1 al 7\n");
        }
    } while (opcion != '7');

    return 0;
}