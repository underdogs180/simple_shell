#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
  unsigned int i;
  builtins_t check[] = {
			{"exit", new_exit},
			{"env", _env},
			{"setenv", NULL},
			{"unsetenv", NULL},
			{NULL, NULL}
  };

  for (i = 0; check[i].f != NULL; i++)
    {
      if (_strcmpr(vars->av[0], check[i].name) == 0)
	break;
    }
  if (check[i].f != NULL)
    check[i].f(vars);
  return (check[i].f);
}
