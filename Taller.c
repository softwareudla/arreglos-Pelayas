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

    printf("\n===INGRESE LAS ASIGNATURAS===\n");
    for (j = 0; j < asignaturas; j++) {
        int valido;
        do {
            valido = 1;
            printf("Ingrese el nombre de la asignatura %d: ", j + 1);
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
                printf("El nombre no puede estar vacío\n");
                valido = 0;
                continue;
            }

            for (int k = 0; asignaturasNombres[j][k] != '\0'; k++) {
                if (asignaturasNombres[j][k] >= '0' && asignaturasNombres[j][k] <= '9') {
                    printf("El nombre no debe contener números\n");
                    valido = 0;
                    break;
                }
            }
        } while (!valido);
    }
      printf("\n===Ingrese los nombres de los estudiantes===\n");

    for (i = 0; i < estudiantes; i++) {
        int valido;
        do {
            valido = 1;
            printf("\nIngrese el nombre del estudiante %d: ", i + 1);
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
                    printf("El nombre no debe contener números\n");
                    valido = 0;
                    break;
                }
            }
        } while (!valido);

        for (j = 0; j < asignaturas; j++) {
            float nota;
            int validoNota = 0;
            do {
                printf("  Ingrese calificación en %s: ", asignaturasNombres[j]);
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

                if (esNumero) {
                    sscanf(entrada, "%f", &nota);
                    if (nota >= 0.0 && nota <= 10.0) {
                        calificaciones[i][j] = nota;
                        validoNota = 1;
                    } else {
                        printf("La nota debe estar entre 0 y 10\n");
                    }
                } else {
                    printf("Entrada inválida solo se permiten números\n");
                }
            } while (!validoNota);
        }
    }

    char opcion;
    do {
        printf("\n=============== MENÚ DE OPCIONES ===============\n");
        printf("1. Promedios por estudiante\n");
        printf("2. Aprobados y reprobados por asignatura\n");
        printf("3. Mayor y menor nota por asignatura\n");
        printf("4. Aprobados y reprobados por estudiante\n");
        printf("5. Mayor y menor nota por estudiante\n");
        printf("6. Promedio por asignatura\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcion = entrada[0];

        switch (opcion) {
            case '1':
                printf("\n--- PROMEDIOS POR ESTUDIANTE ---\n");
                printf("%-20s", "Estudiante");
                for (j = 0; j < asignaturas; j++) printf("%-15s", asignaturasNombres[j]);
                printf("%-10s\n", "Promedio");
                for (i = 0; i < estudiantes; i++) {
                    float suma = 0;
                    printf("%-20s", estudiantesNombres[i]);
                    for (j = 0; j < asignaturas; j++) {
                        printf("%-15.2f", calificaciones[i][j]);
                        suma += calificaciones[i][j];
                    }
                    promedios[i] = suma / asignaturas;
                    printf("%-10.2f\n", promedios[i]);
                }
                break;

            case '2':
                printf("\n--- APROBADOS Y REPROBADOS POR ASIGNATURA ---\n");
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
                printf("\n--- MAYOR Y MENOR NOTA POR ASIGNATURA ---\n");
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
                printf("\n--- APROBADOS Y REPROBADOS POR ESTUDIANTE ---\n");
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
                printf("\n--- MAYOR Y MENOR NOTA POR ESTUDIANTE ---\n");
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
                printf("\n--- PROMEDIO POR ASIGNATURA ---\n");
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
                printf("Saliendo del programa\n");
                break;

            default:
                printf("Opción inválida intenta de nuevo.\n");
        }
    } while (opcion != '7');

    return 0;
}