#include "shell.h"

/** Obtiene la llave de una variable de entorno **/
char *get_key(char *var)
{
    int i;
    char tmp[1000];

	if (!var)
		return (NULL);

    for (i = 0; var[i] != '\0'; i++)
    {
        if (var[i] == '=')
        {
            tmp[i] = '\0';
            return (_strdup(tmp));
        }
        tmp[i] = var[i];
    }
    return (NULL);
}
/** Obtiene el valor de una variable de entorno **/
char *get_value(char *var)
{
    int i, z, y = 0;
    char tmp[1000];

    for (i = 0; var[i] != '\0'; i++)
        if (var[i] == '=')
            break;
    
    if (i)
    {
        for (z = i + 1; var[z] != '\0'; z++)
            tmp[y++] = var[z];
        tmp[y] = '\0';
        return (_strdup(tmp));
    }

    return (NULL);
}
