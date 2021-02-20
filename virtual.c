#include "shell.h"

/** 
	Crea un entorno virtual en memoria estatica pero dinamica (heap)
	Acá se podran obtener las variables desde Linux y, pero tambien creara
	su propio espacio totalmente ajeno a __environ GNU y se podran agregar
	variables totalmente nuevas que no afecten sistemas externos.
	ya que todo sucede en la memoria estatica del programa.

	@flag -> opcion que se ejecutara para manejar enviroment virtual
	@n -> numero de variables leidas
**/
char **VIRTUAL_ENV(size_t *n, const char *flag)
{
	static char **virtual_env = NULL;
	static size_t num = 0;
	size_t i;

	if (!__environ)
		return NULL;
	
	if (eq((char *)flag, "free"))
	{
		if (virtual_env)
			for (i = 0; i < num; i++)
				free(virtual_env[i]);

		free(virtual_env);
		return (NULL);
	}
	else if (eq((char *)flag, "init"))
	{
		if (!virtual_env)
		{
			if (n)
			{
				virtual_env = clone_environ(n);
				num = (int)*n;
				return (virtual_env);
			}
			else
				virtual_env = clone_environ(&num);
			printf("VIRTUAL ENV ALLOCATED: %lo pointers in %p\n",
				num, (void *)virtual_env);
			return (virtual_env);
		}
		return (virtual_env);
	}
	if (n)
		*n = num;
	return (virtual_env);
}
