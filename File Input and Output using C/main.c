#include <stdio.h>  //FILE, scanf, printf, fopen, fclose, perror, fwrite, fread
#include <stdlib.h> //exit, EXIT_SUCCESS
struct Data {
    char name[32];
    int edad;
    float estatura;
};

int load(void *ptr)
{
    struct Data *data = (struct Data *)ptr;
    printf("Nombre: ");
    scanf("%s", data->name);
    printf("Edad: ");
    scanf("%i", &data->edad);
    printf("Estatura: ");
    scanf("%f", &data->estatura);
    printf("\n");
    printf("Nombre: %s \nEdad : %i \nEstatura : %f\n",
           data->name, data->edad, data->estatura);
    printf("\n");
    return EXIT_SUCCESS;
}

int save(void *ap)
{
    struct Data *ptr = (struct Data *)ap;
    FILE *fp;
    fp = fopen("datos.dat", "w+");
    if (fp == NULL)
    {
        perror("Error fopen(...)");
        exit(-1);
    }
    int r = fwrite(ptr, sizeof(struct Data), 1, fp);
    if (r == 0)
    {
    }
    fclose(fp);
    return 0;
}
int read(void *ap)
{
    struct Data *ptr = (struct Data *)ap;
    FILE *fp;
    fp = fopen("datos.dat", "r+");
    if (fp == NULL)
    {
        perror("Error fread(...)");
        exit(-1);
    }
    fread(ptr, sizeof(struct Data), 1, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int main(void)
{
    struct Data data;
    int outLoad = load(&data);
    int outSave = save(&data);
    struct Data dataReader;
    int outRead = read(&dataReader);
    printf("Nombre: %s \nEdad : %i \nEstatura : %f\n",
           dataReader.name, dataReader.edad, dataReader.estatura);
    return EXIT_SUCCESS;
}
